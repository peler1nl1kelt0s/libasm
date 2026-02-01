NAME = libasm.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g
NASM = nasm
NASMFLAGS = -f elf64

SRCS_ASM = ft_strcpy.s ft_strlen.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS_ASM = $(SRCS_ASM:.s=.o)

TEST = runner
TEST_SRC = runner.c
TEST_OBJ = $(TEST_SRC:.c=.o)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS_ASM)
	$(AR) $@ $^

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

test: $(TEST)
	./$(TEST)

$(TEST): $(TEST_OBJ) $(NAME)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJ) -L. -lasm

clean:
	rm -f $(OBJS_ASM) $(TEST_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

