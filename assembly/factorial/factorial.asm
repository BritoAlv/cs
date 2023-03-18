%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging    
    GET_UDEC 8, rdi
    call factorial
    PRINT_UDEC 8, rax
    NEWLINE
    xor rax, rax
    ret
    
factorial:
    cmp rdi, 1
    je .end
    push rbp
    mov rbp, rsp
    push rdi
    ;sub rsp, 8
    ;mov [rsp + 0x8], rdi
    sub rdi,1
    call factorial
    pop rdi
    mul rdi
    ;mul qword [rsp+0x8]
    ;add rsp,8
    pop rbp
    ret      
    .end:
        mov rax, 1
        ret                