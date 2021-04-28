SECTION .text

global _hello
_hello:
	mov rax, 0x2000004      ; syscall 4: write (
	mov rdi, 1              ;    fd,
	mov rsi, Msg            ;    buffer,
	mov rdx, Len            ;    size
	syscall                 ; )
	mov rax, 0x2000004      ; syscall 4: write (
	mov rdi, 1              ;    fd,
	mov rsi, Msg            ;    buffer,
	mov rdx, Len            ;    size
	syscall                 ; )
	ret						;

SECTION .data
Msg db 'Hello world!', 10
Len: equ $ - Msg