NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_printft.c

OBJS = ${FILES:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o %.c:
	$(CC) $(CFLAGS) $(FILES)

clean:
	rm -f (OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
