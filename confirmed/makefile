CFILES = ft_printf.c ft_printf_put.c
OFILES = $(CFILES:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) $(OPTIONS) $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re