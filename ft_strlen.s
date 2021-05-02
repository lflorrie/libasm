section .text
	global ft_strlen
comp:
	cmp byte [r8], 0	; if (s[i] == '\0')
	jle end				; break
	inc r8				;s++
	inc rax				; result++
	jmp comp			;

ft_strlen:
	push rbp ; пушим параметры функции
	mov rax, 0 ; result = 0
	mov r8, rdi
	jmp comp
	
end:
	pop rbp
	ret