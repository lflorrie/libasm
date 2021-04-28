    section .text
    global min
min:

    push rbp
    mov rbp, rsp

    mov rax, [rsp + 8]
    ; mov rcx, [rsp + 16]
    ; cmp rax, rcx
    ; jle end
    ; mov rax, rcx
end:
    pop rbp
    ret