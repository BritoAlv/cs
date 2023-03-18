; this program performs merge-sort to use it, declare an array in source,
; fill helper with zeroes using the same length, and finally pass to :
; rbi = start = 0
; rbx = len(array)-1
%include "io64.inc"

section .data
    source dq 1,2,3,4,2,1
    helper dq 0,0,0,0,0,0


section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    mov rdi, source
    mov rsi, 0 ; beginning at 0
    mov rbx, 5 ; len(array)-1
    call merge_sort
    xor rax, rax
    ret

; takes index of array in rsi, and return in rax => source[rsi]    
source_access:
    mov rax, [source + rsi*8]
    ret
                        
                    
; the recursive funcion merge_sort takes three arguments: 
; int*[]      <= rdi
; int start   <= rsi
; int end     <= rbx

; start => [rsp+0x20]
; (start+end)/2 => [rsp+0x18]
; (start+end)/2 +1 => [rsp+0x10]
; end => [rsp+0x8]
merge_sort:
    cmp rsi, rbx
    jge .end
    push rbp
    mov rbp, rsp
    sub rsp, 32
    
    mov [rsp + 0x20], rsi
    mov rax, rsi
    add rax, rbx
    
    xor rdx, rdx
    mov rcx, 2
    div rcx
    mov [rsp + 0x18], rax
    inc rax
    mov [rsp + 0x10], rax
    mov [rsp+0x8], rbx
    
    mov rsi, [rsp + 0x20]
    mov rbx, [rsp + 0x18]
    call merge_sort
    
    mov rsi, [rsp + 0x10]
    mov rbx, [rsp + 0x8]
    call merge_sort
    
    mov rsi, [rsp + 0x20]                                                      
    mov rbx, [rsp + 0x8 ]
    call merge
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    add rsp, 32
    pop rbp
    .end:
        ret


; this funcion merge takes three arguments: 
; int*[]      <= rdi
; int start   <= rsi
; int end     <= rbx

; have as local variables
; (start+end)/2 => [rsp + 0x30]
; start         => [rsp + 0x28]
; end           => [rsp + 0x20]
; finger1       => [rsp + 0x18]
; finger2       => [rsp + 0x10]
; pointer       => [rsp + 0x8] 
merge:
    push rbp
    mov rbp, rsp
    sub rsp, 0x30
    mov [rsp + 0x28], rsi
    mov [rsp + 0x20], rbx
    mov [rsp + 0x18], rsi
    mov rax, rsi
    add rax, rbx
    xor rdx, rdx
    mov rcx, 2
    div rcx
    inc rax
    mov [rsp + 0x10], rax
    dec rax
    mov [rsp + 0x30], rax
    mov qword [rsp + 0x8], 0
    firstwhile:
        mov  rax, [rsp + 0x30]
        cmp [rsp + 0x18], rax
        jg secondwhile
        mov rax, [rsp + 0x20]
        cmp [rsp + 0x10], rax
        jg secondwhile
        mov rsi, [rsp + 0x10]
        call source_access
        mov rcx, rax
        mov rsi, [rsp + 0x18]
        call source_access
        cmp rax, rcx
        jge .else
        .if:  
            inc qword [rsp + 0x18]
            jmp .end 
        .else:
            mov rax, rcx
            inc qword [rsp + 0x10]
        .end:
            mov rcx, [rsp + 0x8]
            mov [helper + rcx*8], rax    
            inc qword [rsp+0x8]    
            jmp firstwhile    
    secondwhile:
        mov rax, [rsp+0x18]
        cmp rax, [rsp+0x30]
        jg thirdwhile
        mov rsi, rax
        call source_access
        mov rcx, [rsp + 0x8]
        mov [helper + rcx*8], rax    
        inc qword [rsp+0x8]
        inc qword [rsp+0x18]
        jmp secondwhile    
    thirdwhile:
        mov rax, [rsp+0x10]
        cmp rax, [rsp+0x20]
        jg for
        mov rsi, rax
        call source_access
        mov rcx, [rsp + 0x8]
        mov [helper + rcx*8], rax    
        inc qword [rsp+0x8]
        inc qword [rsp+0x10]
        jmp thirdwhile
    
    for:
        mov rax, [rsp+0x28]
        .loop:
            cmp rax, [rsp+0x20]
            jg .end
            mov r9, rax
            sub r9, [rsp+0x28]
            mov r9, [helper + r9*8] 
            mov [source + rax*8], r9
            inc rax
            jmp .loop 
    .end:
    add rsp, 0x30
    pop rbp
    ret            