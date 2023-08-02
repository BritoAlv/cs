; this will simulate a heap with an source
; of at most 1000 elements.

%include "io64.inc"

section .data
    source  times 1000 dq 0
    output  times 1000 dq 0
    len dq  0 ; stores actual length of the heap.

section .text
global CMAIN

CMAIN:
    push rbp
    mov rbp, rsp          ; for correct debugging
    PRINT_STRING "Hola, len(array): "
    GET_UDEC 8, rax       ; store in rax len of string.
    mov [len], rax        ; save in len the len of the string.
    NEWLINE
    mov rax, 0            ; rax will be pointer to access array.
    .input_loop:          ; accept len values and save them in source array.
        cmp rax, [len]
        je .take_input_end
        GET_UDEC 8, rcx
        mov [source + rax*8], rcx 
        inc rax
        jmp .input_loop
        NEWLINE
    .take_input_end:     
    mov  rsi, [len]
    push rsi
    call heap_sort
    pop rsi
    mov rax, 0
    NEWLINE
    .output_loop:
        cmp rax, rsi 
        je .end
        PRINT_UDEC 8, [output + rax*8]
        NEWLINE
        inc rax
        jmp .output_loop
    .end:
    pop rbp
    ret 
    


; return in rax the minimum element in the heap.
get_min: 
    mov rax, [source]
    ret    

; takes index in rsi, return in rax <- source[rsi]
access_source:
    mov rax, [source + 8*rsi]
    ret 

; takes index in rsi, return in rax <- (rsi-1)/2
index_father:
    mov rax, rsi
    dec rax
    shr rax, 1
    ret 

; takes index in rsi, return in rax <- 2*rsi+1
index_lchild:
    mov rax, rsi
    shl rax, 1
    inc rax
    ret

; takes index in rsi, return in rax <- 2*rsi+2        
index_rchild:
    call index_lchild
    inc rax
    ret    

; takes two index i, j at rsi, rdi: swap {source[i], source[j]}, swap {rsi, rdi}.
swap:
    call access_source           ; rax <- source[i]
    push rax                     ; save source[i]
    xchg rsi, rdi                ; swap index to call access_source
    call access_source           ; rax <- source[j]
    mov [source + rdi*8], rax
    pop rax 
    mov [source + rsi*8], rax
    ret

; takes two index i,j located at rsi, rdi, and compare source[i] with source[j]
compare_two:
    call access_source ; rax <- source[i].
    push rax           ; save it.
    xchg rsi, rdi     
    call access_source ; rax <- source[j].
    xchg rsi, rdi
    pop rdx            ; rbx <- source[i].
    cmp rdx, rax       ; compare.
    ret     
            
; take index in rsi , it does not return anything.        
fix_father:
    call index_father     ; rax contains index of father.
    cmp  rax, 0           ; check if index of father is valid.
    jl   .end               
    mov rdi, rsi          ; rsi <- index_father, rdi <- actual_index.
    mov rsi, rax 
    call compare_two      ; active flags. 
    jl .end               ; we should swap and call function at index_father.                                    
    call swap             ; this relies also in the fact that swap also swap rsi, rdi.
    call fix_father       ; rsi <- index_father.
    .end:
        ret

; take index in rsi , it does not return anything.  
fix_child:
    call index_rchild
    mov  rbx, rax       ; rbx <- rchild_index.
    dec  rax            ; rax <- lchild_index.
    cmp  rbx, [len]     ; check if node has two childs.
    jge  no_two_childs   
    ; two childs, so we need to move index of smaller node to rdi,
    ; compare to decide if swap and continue the process.
    push rsi           ; save index.
    mov  rdi, rax      ; rdi <- lchild_index.
    mov  rsi, rbx      ; rsi <- rchild_index.
    
    call compare_two   ; compare its source[values]
    jg already_done   ; if left child is greater then move to rdi its index.   
    mov rdi, rbx
           
    already_done:      ; at this point rdi contains index of smallest child.
        pop rsi        ; rsi <- index, rdi <- index of smallest child.
        call compare_two
        jle the_end        
        call swap      ; after swap rsi <- index of smallest child.
        call fix_child
        jmp the_end
            
    no_two_childs:
        cmp rax, [len]
        jge the_end        
        ; in this part there is only one child.    
        mov rdi, rax           ; rsi <- actual_index, rdi <- lchild_index.  
        call compare_two       ; does not have aside effects.
        jle the_end
        call swap              ; rsi <- lchild_index.
        call fix_child
    the_end:
        ret

; value to insert in rsi, it does not return anything.
insert:
    mov rax, [len]
    mov [source + 8*rax], rsi
    inc qword [len]
    mov rsi, rax
    call fix_father    
    ret

; extracted min in rax.
extract_min:
    cmp qword [len], 0
    je .end

    cmp qword [len], 1
    jne .else
    
    ; heap contains only one element.
    mov rax, [source]          ; move element to rax.
    mov qword [source], 0      ; set source[0] = 0.
    dec qword [len]            ; set [len] = 0.
    jmp .end    
    
    .else:
        mov  rax, [source]      ; move rax <- min          
        push rax
        mov  rdi, 0             ; rsi <- 0
        dec  qword [len]
        mov  rsi, [len]         ; rdi <- len - 1 
        call swap               ; swap those values, so that rsi <- 0
        call fix_child
        pop  rax                   
    .end:
        ret
        
        
; takes in rsi, len of the source.    
build_heap:
    shr rsi, 1
    dec rsi        ; rax <- len/2-1
    .loop:
        cmp  rsi, 0 
        jl   .end
        push rsi
        call fix_child
        pop  rsi
        dec  rsi
        jmp  .loop    
    .end:
        ret


; takes in rsi, len of the source.
heap_sort:
    push rbp
    mov  rbp, rsp
    sub  rsp, 8
    mov  [rsp+0x8], rsi
    call build_heap
    mov  rbx, 0
    .loop:
        cmp   rbx, [rsp+0x8]  
        je    .end
        push  rbx
        call  extract_min
        pop   rbx
        mov   [output + rbx*8], rax
        inc   rbx
        jmp   .loop
    .end:
        add rsp, 8
        pop rbp
        ret       