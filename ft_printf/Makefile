CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -cr
SRCS = ft_printf.c

SRCS_BNS = .c

OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRCS:.c=.o) $(SRCS_BNS:.c=.o)
LIBFT = libft.a
LIBFT_DIR = libft
NAME = libftprintf.a


all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	mv $(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $^

bonus : $(OBJS_BNS) 
	$(AR) $(ARFLAGS) $(NAME) $^

clean :
	rm -f $(OBJS) $(OBJS_BNS)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $^
