section .text
	global ft_strcmp
comp:
	mov r10, [r8]
	and r10, 127
	mov rax, r10

	mov r11, [r9]		; s2[i]
	and r11, 127		; take only 1 byte
	sub rax, r11		; diff = s1[i] - s2[i]
	
	cmp rax, 0			; 
	jg end2				; if (diff > 0) result = 1
	jl end3				; if (diff < 0)else result = -1

	cmp byte [r8], 0	; if (s[i] == '\0')
	je end				; ZF = 1
	
	inc r8				; s1++
	inc r9				; s2++
	jmp comp			;

ft_strcmp:
	push rbp 			; пушим параметры функции
	mov r8, rdi
	mov r9, rsi
	jmp comp

end2:
	mov rax, 1
	jmp end
end3:
	mov rax, -1
end:
	pop rbp
	ret