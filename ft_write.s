global ft_write
extern ___errno_location

section .text
ft_write:
	mov rax, 1
	syscall

	cmp rax, 0
	je .done

	neg rax
    mov     rdi, rax
    call    __errno_location
    mov     [rax], edi
    mov     rax, -1

.done 
	ret

