%include "io64.inc"
section .data
    hola db "Hola: "
    len_hola equ $-hola
    
    bienvenido db ".", 10,"Bienvenido al NASM.", 10
    len_bienvenido equ $-bienvenido
    
section .bss
    name resb 16        
section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    
    ; setting welcome message
    mov rsi, hola
    mov rdx, len_hola
    call print_string

    ; setting read input
    mov rsi, name
    mov rdx, 16
    call read_input
   
    call print_string

    ; setting welcome message    
    mov rsi, bienvenido
    mov rdx, len_bienvenido
    
    call print_string
    
    call exit_program

read_input:
    mov rax, 0
    mov rdi,0
    syscall
    ret

exit_program:   
    mov rax, 60
    mov rdi, 0
    syscall 
            
print_string: ; assuming you already put in the
              ; registers the len of the string and the address of its start
    mov rax, 1
    mov rdi, 1
    syscall
    ret    
