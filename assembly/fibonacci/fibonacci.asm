; this program should print the n-first fibonacci numbers.
%include "io64.inc"

section .data
    pointer dq 2
section .bss
    dynamic_array resq 1600
    
section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    GET_UDEC 8, rdi
    mov qword [dynamic_array], 1
    mov qword [dynamic_array + 0x8], 1
    call fibonacci
    mov rax, 0 
    call print_array
    xor rax, rax
    ret

print_array:
    cmp rax, rdi
    jge .end
    PRINT_UDEC 8, [dynamic_array + rax*8]
    NEWLINE
    inc rax
    jmp print_array
    .end:
        ret
    
    
fibonacci:
    cmp rdi, [pointer]
    jle .dynamic_end
    cmp rdi, 2
    jle .end
    push rbp
    mov rbp, rsp
    sub rsp, 16
    
    mov [rsp+0x10],  rdi
    sub qword [rsp+0x10],  1
    
    mov  [rsp+0x8], rdi
    sub  qword [rsp+0x8],  2
    
    mov rdi, [rsp + 0x10] ; 0x10 = 16 in hex = 2 slots for 8 bytes = int 64
    call fibonacci
    mov [rsp + 0x10], rax     
    
    mov rdi, [rsp + 0x8]
    call fibonacci
    
    add rax, [rsp+0x10]
    
    add qword [pointer], 1
    mov rdi, [pointer]
    mov [dynamic_array + (rdi-1)*8], rax
    
    
    add rsp, 16
    pop rbp 
    ret
                                                    
    .end:
        mov rax, 1
        ret
    .dynamic_end:
        mov rax, [dynamic_array + (rdi-1)*8 ]
        ret    