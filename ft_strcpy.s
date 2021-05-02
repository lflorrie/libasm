section .text
	global ft_strcpy

cpy:
	mov r10, [r9]
	and r10, 127		; take only 1 byte
	mov [r8], r10		; copy 1 byte in s1
	
	cmp r10, 0		; if (s2[i] == 0) return 
	jle end
	inc r8				; ++s1;
	inc r9				; ++s2;
	jmp cpy

ft_strcpy:
	push rbp			; пушим параметры функции
	mov r8, rdi			; s1
	mov r9, rsi			; s2
	jmp cpy

end:
	mov rax, rdi
	pop rbp
	ret