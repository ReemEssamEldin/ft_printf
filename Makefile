CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utills.c
# output library name
NAME = libftprintf.a
HEADER = ft_printf.h

# object files
OBJS = $(SRCS:.c=.o)

# build the library
all: $(NAME)

%.o: %.c
	cc -I $(HEADER) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Clean object files
clean:
	rm -rf $(OBJS)
	echo "$(OBJs) deleted"

# Clean object files and the library
fclean: clean
	rm -rf $(NAME)
	echo "$(NAME) deleted"

# Rebuild the library
re: fclean all

# Phony targets
.PHONY: all clean fclean re
