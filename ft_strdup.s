section .text
	extern malloc
	extern ft_strlen
	extern ft_strcpy
	global ft_strdup

ft_strdup:
	push rbp			; пушим параметры функции
	
	mov r12, rdi		; s1


	call ft_strlen
	mov r9, rax			; len
	add r9, 1			; len + 1 (\0)

	mov rdi, r9			; malloc (r9)
	call malloc
	test rax, rax
	jz   fail_exit		; if memory was not allocated 

	mov rdi, rax		; dst
	mov rsi, r12		; src
	call ft_strcpy		; copy src -> dst
	jmp end

end:
	pop rbp
	ret

fail_exit:
	mov rax, 0
	pop rbp
	ret