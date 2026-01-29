global ft_strcpy

section .text:

ft_strcpy:
	
.loop:
	cmp byte [rdi], 0
	je .done

.done:
	ret