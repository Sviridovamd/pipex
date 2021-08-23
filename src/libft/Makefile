NAME = libft.a
HEAD = libft.h
SRC = ft_atoi.c	ft_memchr.c	ft_strnstr.c ft_bzero.c ft_strchr.c ft_memcmp.c ft_strdup.c	ft_strrchr.c ft_calloc.c ft_memcpy.c ft_strjoin.c ft_substr.c ft_isalnum.c ft_memmove.c ft_strlcat.c ft_tolower.c ft_isalpha.c ft_memset.c ft_strlcpy.c ft_toupper.c ft_isascii.c ft_putchar_fd.c ft_isdigit.c ft_putendl_fd.c ft_strlen.c ft_isprint.c ft_putnbr_fd.c ft_strmapi.c ft_memccpy.c ft_putstr_fd.c ft_strncmp.c ft_itoa.c ft_strtrim.c ft_split.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

.c.o:
	$(CC) $(FLAGS) -I $(HEAD) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all