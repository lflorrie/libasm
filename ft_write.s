section .text
	extern error
	global ft_write

ft_write:
	push rbp 				; пушим параметры функции
	mov rax, 1				; syscall 4: write (
	syscall					; )
end:
	pop rbp
	ret