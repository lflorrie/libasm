SECTION .text

global hello
hello:
	mov rax, 1				; syscall 4: write (
	mov rdi, 1				;    fd,
	mov rsi, Msg			;    buffer,
	mov rdx, Len			;    size
	syscall					; )
	ret						;

SECTION .data
Msg db 'Hello world!', 10
Len: equ $ - Msg