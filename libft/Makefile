CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLASGS = crv
SRCS = 
OBJS = $(SRCS:.c=.o))
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $^ 
