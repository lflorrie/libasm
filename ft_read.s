section .text
	global ft_read

ft_read:
	push rbp 				; пушим параметры функции
	mov rax, 0				; syscall ?: read (
	syscall					; )

end:
	pop rbp
	ret