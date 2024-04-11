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
		types/ft_nbr.c \
		types/ft_uint.c \
		types/ft_ptr.c

OBJS = ${FILES:.c=.o}
OBJSTYPES = ${FILESTYPES:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(OBJSTYPES)
	@make -C $(LIBFTPATH)
	@cp $(LIBFTPATH)/libft.a .
	@mv $(LIBFTPATH)/libft.a $(NAME)
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
	$(CC) $(CFLAGS) test.c libftprintf.a libft.a
	./a.out

.PHONY: all clean fclean re test
