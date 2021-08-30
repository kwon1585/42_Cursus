CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -cr
SRCS = ft_printf.c ft_printf_utils.c check.c \
		print_char.c print_str.c print_addr.c \
		print_dec.c print_hex.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_BNS)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $^
