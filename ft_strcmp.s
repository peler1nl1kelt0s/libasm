global ft_strcmp

section .text
ft_strcmp:
    xor rax, rax

.loop:
    mov dl, byte [rdi]
    mov cl, byte [rsi]

    cmp dl, cl
    jne .notequal

    cmp dl, 0
    je .done

    inc rdi
    inc rsi
    jmp .loop

.notequal:
    movzx eax, dl
    movzx ecx, cl
    sub eax, ecx

.done:
    ret
