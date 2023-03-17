fibonacci:
        push    rbp
        mov     rbp, rsp
        push    rbx
        sub     rsp, 24
        mov     dword [rbp-0x14], edi
        cmp     dword [rbp-0x14], 2
        jg      L_001
        mov     eax, 1
        jmp     L_002

L_001:  mov     eax, dword [rbp-0x14]
        sub     eax, 1
        mov     edi, eax
        mov     eax, 0
        call    f
        mov     ebx, eax
        mov     eax, dword [rbp-0x14]
        sub     eax, 2
        mov     edi, eax
        mov     eax, 0
        call    f
        add     eax, ebx

L_002:  mov     rbx, qword [rbp-0x8]
        leave
        ret


