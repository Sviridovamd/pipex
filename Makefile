NAME = pipex

CC = gcc

LIBFTDIR = ./src/libft

LIBFT = $(LIBFTDIR)/libft.a

FLAGS = -g -Wall -Wextra -Werror

FILES_PIPEX = pipex.c ./src/extra.c

OBJS = $(FILES_PIPEX:.c=.o)
D_FILES = $(FILES_PIPEX:.c=.d)

.c.o:
	$(CC) $(FLAGS) -I $(LIBFT) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) | tools
		$(CC) $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME)

include $(wildcard $(D_FILES))

tools:
	make -C $(LIBFTDIR)
	rm -f infile
	touch infile
norm:
	norminette -R $(LIBFTDIR)/*.c ./src/*.c ./src/*.h *.c

clean:
	rm -f $(OBJS) $(D_FILES)
	make -C $(LIBFTDIR) clean
fclean: clean
	rm -f ${NAME} infile outfile
	make -C $(LIBFTDIR) fclean
re: fclean all
