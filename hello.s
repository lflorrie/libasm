section .text
global hello
hello:
	mov rax, 1			; write(
	mov rdi, 1			;   STDOUT_FILENO,
	mov rsi, msg		;   "Hello, world!\n",
	mov rdx, msglen		;   sizeof("Hello, world!\n")
	syscall				; );
	ret					;// essentially identical to: pop [register] -> jmp [register]

section .data
  msg: db "Hello, world!", 10
  msglen: equ $ - msg
