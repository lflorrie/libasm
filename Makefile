CC = nasm
LD = ld
FLAGS =-f macho64

NAME = hello

SRCS = hello.s min.s

OBJ = $(SRCS:.s=.o)

.PHONY: all re clean fclean

all:$(NAME)

%.o:%.s
	$(CC) $(FLAGS) $< -o $@

$(NAME):$(OBJ)
	$(LD) -macosx_version_min 10.7.0 $(OBJ) -o $(NAME) -no_pie

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

test:$(OBJ)
	gcc $(OBJ) ft_tests.c -o test

re:fclean all
	