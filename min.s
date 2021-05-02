    section .text
    global min
min:

    push rbp
    ;mov rbp, rsp
    mov rax, rdi
    cmp rdi, rsi
    jle end
    mov rax, rsi
end:
    pop rbp
    ret