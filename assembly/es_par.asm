%include "io64.inc"
section .data

section .bss
    number resb 4
    
section .text
    global CMAIN
    
CMAIN:
    mov rbp, rsp; for correct debugging
    PRINT_STRING "Pon un número: "     
    
    GET_UDEC 4, number ; 4 bytes are 32 bits => int32.
    PRINT_UDEC 4, number
    
    mov eax, [number]     ; dividend
    mov edx, 0            ; remainder
    mov ebx, 2            ; divisor can be any register or memory  
    div ebx
    
    cmp edx, 0
    je esPar
    jne esImpar             
    
    call _exit
    
_exit:
    mov rax, 60         ; code for calling sys_exit
    mov rdi, 0          ; 0 because it worked fine
    syscall
    
esPar:
    PRINT_STRING " It's Even"
    ret
    
esImpar:
    PRINT_STRING " It's Odd"
    ret    
    
        
                                                                                                                                 
                                                                                                                                                                                                                                                                                                                                                                                           