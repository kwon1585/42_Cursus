#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char t = 'A';
	char k = '@';
	printf("hello world %p\n", &t);
	ft_printf("hello world %p", &t);
}
