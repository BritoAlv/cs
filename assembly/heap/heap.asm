; this will simulate a heap with an source
; of at most 100 elements.

%include "io64.inc"

section .data
    source  dq 10, 11, 12, 13, 14, 15, 9, 8
    helper  times 1000 dq 0
    len dq  8 

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    sub rsp, 8
    PRINT_STRING "Hola, len(array): "
    GET_UDEC 8, rax
    NEWLINE
    mov rbx, 0
    .loop:
        cmp rax, 0
        je .fend
        GET_UDEC 8, rcx
        mov [source + rbx*8], rcx 
        add  rbx, 1
        sub  rax, 1
        jmp .loop
        NEWLINE
    .fend:     
    mov rdi, source
    mov rsi, 0 ; beginning at 0
    dec rbx
    ; i think that in rbx is len(array)-1
    call merge_sort
    
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
    


; return in rax the minimum element in the heap.
get_min: 
    mov rax, [source]
    ret    

; take index in rsi.
access_source:
    mov rax, [source + 8*rsi]
    ret 

; take index in rsi.
; return in rax index of father.
index_father:
    mov rax, rsi
    dec rax
    shr rax, 1
    ret 

index_lchild:
    mov rax, rsi
    shl rax,1
    inc rax
    ret
    
index_rchild:
    mov rax, rsi
    shl rax,1
    inc rax
    inc rax
    ret    

; take index in rsi, rdi, swap those two values.
swap:
    call access_source           ; rax <= source[rsi]
    push rax                    ; we save it
    push rsi
    mov  rsi, rdi               ; setup to compute source[rdi]
    call access_source           ; rax <= source[rdi]
    pop  rsi
    mov  [source + 8*rsi], rax   
    pop  rax
    mov  [source + 8*rdi], rax
    ret
    
; take index in rsi.        
fix_father:
    call index_father    ; rax contains index of father.
    cmp  rax, 0          ; index of father is valid so we compare it
    jl   end             ; with the actual index.
    
    push rsi ; push actual index
    push rax ; push index of father
    call access_source ; get source[index]
    mov rbx, rax ; move it to rbx
    pop rsi ; restore index of father.
    call access_source ; get source[father]
    cmp rbx, rax
    jge end
    pop rdi   ; get actual index in rdi.
    push rsi
    call swap
    pop  rsi
    call fix_father    
    end:
        ret

; take index in rsi.
; 
fix_child:
    call index_rchild
    mov rbx, rax
    call index_lchild
    
    cmp rbx, [len]
    jge no_two_childs  
    ; we have at rsi actual index,
    ; need to move to rdi, index
    ; of smallest two children, after
    ; compare to decide if swap an continue the process.
    
    ; rax <= 2*index+1
    ; rbx <= 2*index+2
    mov r14, qword [source + 8*rbx]
    mov r15, qword [source + 8*rax]
    cmp r14, r15
    jg there_is_swap
    
    mov rdi, rbx
    jmp already_done  
    
    there_is_swap:    
        mov rdi, rax
           
    already_done: ; rdi contains index of smallest child
        push rsi
        call access_source ; rbx contains A[index]
        mov rbx, rax 
        mov rsi, rdi 
        call access_source ; rax contains A[child]
        pop rsi
        cmp rax, rbx
        jge end
        
        call swap
        mov rsi, rdi
        call fix_child
        
    jmp end
    no_two_childs:
        cmp rbx, [len]
        jne .end
        
        ; in this part there is only one child.    
        
        mov rdi, rax
        call access_source 
        mov rbx, rax ; rbx contains source[index]
        push rsi
        mov rsi, rdi
        call access_source
        pop rsi
        cmp rax, rbx
        jge end
        
        call swap
        mov rsi, rdi
        call fix_child
    .end:
        ret

; value to insert in rsi
insert:
    mov rax, [len]
    mov [source + 8*rax], rsi
    mov rsi, rax
    call fix_father
    mov rax, [len]
    inc rax
    mov [len], rax    
    ret

; extracted min in rax.
extract_min:
    mov rax, [len]
    cmp rax, 1
    jne .else
    
    mov rax, [source]
    mov qword [source], 0
    
    mov rcx, [len]
    dec rcx    
    mov [len], rcx
    
    jmp .end    
    
    .else:
        mov rcx, [len]
        dec rcx
        mov rbx, [source + 8*rcx]
        mov qword [source+8*rcx], 0
        mov rax, [source]
        mov [source], rbx
        mov [len], rcx
        mov rsi, 0
        push rax
        call fix_child
        pop rax
                      
    .end:
        ret
; takes in rsi, len of the source.    
build_heap:
    mov rax, rsi
    shr rax,1
    dec rax
    .loop:
        cmp rax, 0
        jl .end
        mov rsi, rax
        push rax
        call fix_child
        pop  rax
        dec rax
        jmp .loop    
    .end:
        ret


; takes len of source in rsi.
heap_sort:
    push rsi
    call build_heap
    pop  r13
    mov  r12, 0
    .loop:
        cmp r12, r13
        jge .end
        call extract_min
        mov [helper + 8*r12], rax
        inc r12
        jmp .loop
    .end:
        ret