NAME    = ip_cal.out
CC      = gcc
RM      = rm
RMFLAG  = -f
SRC     = \
	ipcal.c\
	ipcal_atoi.c\
	ipcal_check_form.c\
	ipcal_error.c\
	ipcal_get_next_line.c\
	ipcal_info.c\
	ipcal_itoa.c\
	ipcal_readfile.c\
	ipcal_utils.c
OBJS    = $(SRC:.c=.o)

all : $(NAME)

.c.o : 
	$(CC) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(CC) -o $@ $?
	cat f_header

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

