; this program performs quick-sort.
%include "io64.inc"

section .data
    source times 1000 dq 0

section .text
global CMAIN
CMAIN:
    push rbp
    mov rbp, rsp; for correct debugging
    sub rsp, 8
    PRINT_STRING "Hola, len(array): "
    GET_UDEC 8, rax
    mov [rsp+0x8], rax
    NEWLINE
    mov rbx, 0
    .loop:
        cmp rax, 0
        je .fend
        GET_UDEC 8, rcx
        mov  [source + rbx*8], rcx 
        add  rbx, 1
        sub  rax, 1
        jmp  .loop
        NEWLINE
    .fend:     
    mov rdi, source
    mov rsi, 0 ; beginning at 0
    dec rbx
    ; i think that in rbx is len(array)-1
    call quick_sort
    
    mov rbx, 0
    mov rcx, [rsp+0x8]
    dec rcx
    NEWLINE
    .lloop:
        cmp rbx, rcx 
        jg .end
        PRINT_UDEC 8, [source + rbx*8]
        NEWLINE
        inc rbx
        jmp .lloop
    .end:
    xor rax, rax
    add rsp, 8
    pop rbp
    ret 




; at rsi, should be start:
; at rbx, should be end:
quick_sort:
    cmp rsi, rbx
    jge .end
    push rbp
    mov rbp, rsp
    sub rsp, 24
    mov [rsp+0x18], rsi 
    mov [rsp+0x8],  rbx
    
    call partition
    
    mov [rsp+0x10], rax
    dec rax
    mov rbx, rax
    mov rsi, [rsp+0x18]
    
    call quick_sort
    
    mov rsi, [rsp+0x10]
    add rsi, 1
    mov rbx, [rsp+0x8]
    call quick_sort    

    add rsp, 24
    pop rbp
    .end:
    ret
    
; at rsi, should be i:
; at rcx, should be j;
swap:
    push rax
    push rbx
    mov  rax,  [source + rsi*8]
    mov  rbx , [source + rcx*8]
    mov  [source + rsi*8] , rbx
    mov  [source + rcx*8] , rax
    pop  rbx
    pop  rax
    ret

; => in rdi, there should be a pointer to the array.
; => in rsi, there should be start
; => in rbx, there should be end ( initially len(array)-1 )
; => return in rax, final_position
; [rsp+0x8] pivot
partition:
    push r9 ; i will use r9 for the for.
    mov  r9, rsi
    mov  rax, rsi ; final position will be in rax.
    .for:
        cmp r9, rbx
        jg .end
        mov rdx, [source + r9*8]
        cmp rdx, [source + rbx*8]
        jge .endd
        mov rsi, r9
        mov rcx, rax
        call swap
        inc rax
        .endd:
        inc r9
        jmp .for
    .end:
    pop r9
    mov rsi, rax
    mov rcx, rbx
    call swap
    ret