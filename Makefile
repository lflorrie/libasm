CC = nasm
LD = ld
FLAGS =-felf64

NAME = hello

SRCS = hello.s min.s

OBJ = $(SRCS:.s=.o)

.PHONY: all re clean fclean

all:$(NAME)

%.o:%.s
	$(CC) $(FLAGS) $< -o $@

$(NAME):$(OBJ)
	$(LD) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

test:$(OBJ)
	gcc $(OBJ) ft_tests.c -o test
re:fclean all
	