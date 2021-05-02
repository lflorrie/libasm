CC = nasm
LD = ld
FLAGS =-f macho64
FLAGS_LINUX = -felf64

NAME = hello

SRCS = hello.s min.s ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s

OBJ = $(SRCS:.s=.o)
.PHONY: all re clean fclean

all:$(NAME)

%.o:%.s
	$(CC) $(FLAGS_LINUX) $< -o $@
# 	$(CC) $(FLAGS) $< -o $@

$(NAME):$(OBJ)
	$(LD) $(OBJ) -o $(NAME) # linux
# 	$(LD) -macosx_version_min 10.7.0 $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

test:fclean $(OBJ)
	gcc -no-pie $(OBJ) ft_tests.c -o test

re:fclean all
	