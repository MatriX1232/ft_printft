NAME = libftprintf.a

LIBFTPATH = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = \
		ft_printf.c \

FILESTYPES = \
		types/ft_char.c \
		types/ft_str.c \
		types/ft_hex.c \

OBJS = ${FILES:.c=.o}
OBJSTYPES = ${FILESTYPES:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(OBJSTYPES)
	@make -C $(LIBFTPATH)
	ar -rcs $(NAME) $(OBJS) $(OBJSTYPES)

clean:
	rm -f $(OBJS) $(OBJSTYPES)
	@make clean -C $(LIBFTPATH)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFTPATH)

re: fclean all

test:
	@make
	$(CC) $(CFLAGS) test.c libftprintf.a libft/libft.a
	./a.out

.PHONY: all clean fclean re test
