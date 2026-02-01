NAME = libasm.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g
NASM = nasm
NASMFLAGS = -f elf64

SRCS_ASM = ft_strcpy.s ft_strlen.s ft_strcmp.s ft_write.s
OBJS_ASM = $(SRCS_ASM:.s=.o)

DENEME = deneme
DENEME_SRC = deneme.c
DENEME_OBJ = $(DENEME_SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME) $(DENEME)

$(NAME): $(OBJS_ASM)
	$(AR) $@ $^

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

$(DENEME): $(DENEME_OBJ) $(NAME)
	$(CC) $(CFLAGS) -o $@ $(DENEME_OBJ) -L. -lasm

clean:
	rm -f $(OBJS_ASM) $(DENEME_OBJ)

fclean: clean
	rm -f $(NAME) $(DENEME)

re: fclean all

