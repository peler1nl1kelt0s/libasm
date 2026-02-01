global ft_read
extern __errno_location
section .text
ft_read:
	mov rax, 0
	syscall

	test rax, rax
	jns .done

	neg rax
    mov     rdi, rax
	call    __errno_location
    mov     [rax], edi
    mov     rax, -1

.done:
	ret