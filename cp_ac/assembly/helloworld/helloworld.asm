%include "io64.inc"
section .data 
    message: db "Hello World", 10 ; define a constante string variable ending in ASCII("\n") = 10.
    len: equ $-message            ; compute the length of message array.
    ;$ represents the next free location or offset that could hold a byte (here, 
    ;in the data section, at runtime).
    ;Thus the expression $ - myString produces the difference between that next location
    ;and the label.  Since that label occurs earlier, 
    ;this difference is a positive value, and in fact it is 
    ;the total length of the preceding db.message

    ;The equ says to define lengthofString as a compile time constant, 
    ;which doesn't consuming any runtime storage.

    ;Note that for this to work, this equ expression containing $ must appear immediately after
    ;the string.  Otherwise, if there were intervening data declarations, 
    ;the count would include them as well, which would be bad.                               
    

section .text
global CMAIN
CMAIN:
    push rbp
    mov rbp, rsp        ; for correct debugging
    mov rax, 1          ; code for calling sys_rax
    mov rsi, message    ; pointer to address in memory where is the message
    mov rdx, len        ; longitud en memoria del carácter 
    syscall
    pop rbp
    mov rax, 60         ; code for calling sys_exit
    mov rdi, 0          ; 0 because it worked fine
    syscall
    