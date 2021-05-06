CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLASGS = crv
HEAD = libft.h
SRCS = ft_memset.c ft_bzero.c
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all : $(NAME)

$(NAME) : $(HEAD) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $^ 
