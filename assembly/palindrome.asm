; given an array of strings defined in section.data, print if they are palyndromes
%include "io64.inc"
section .data:
    array: db 0, "AAA", 0, "ABA", 0, "AlvalA", 0, "ANGA", 0, "WEEEW", 0, "WWW",0 
section .text

global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ; move the pointer of the array to ta position after a 0 always, 
    ; that's where the algorithm should start.
    
    mov rdi, array
    
    .repeat:
        mov al, byte [rdi]     
        cmp al, 0
        je .found_zero  
        inc rdi
        jmp .repeat
        .found_zero:
            inc rdi
            mov al, byte [rdi]
            cmp al, 0
            jne .found_word
            ret
            .found_word:
                 call setup
                 jmp .repeat    
        
setup:
    call len_string
    mov rsi, rax
    call is_palyndrome
    cmp rax,1
    jne .no_es
    PRINT_STRING "So Far, So Good"
    NEWLINE
    ret
    .no_es:
    PRINT_STRING "Niet"
    NEWLINE
    ret  

      
is_palyndrome:
    cmp rsi, 1
    jg .opportunity_1
    mov rax,1
    ret
    .opportunity_1:
    call check_palyndrome
    cmp rax, 1
    je .opportunity_2
    mov rax, 0
    ret
    .opportunity_2:
    inc rdi
    sub rsi, 2
    jmp is_palyndrome

len_string: ; premature optimization is the root of all devil.
    .setup:
    xor rax, rax
    .do_while:
    push rdx ; preserve rdx register value
    mov dl, [rdi+rax]    
    cmp dl, 0
    pop rdx ; preserve rdx register value
    je .end
    inc rax
    jmp .do_while
    .end:
        ret

check_palyndrome:  
    push rdx ; preserve value of register but it's not needed.
    mov  dl,  [rdi] 
    cmp  dl, byte [rdi+rsi-1]
    jnz  .not_equal
    mov  rax, 1
    jmp  .after
    .not_equal:
    mov rax, 0
    .after:
    pop rdx ; preserve value of register but it's not needed.
    ret