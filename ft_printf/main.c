#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int t = 42;
	char k = '@';
	printf("hello world %p\n", &t);
	ft_printf("hello world %p", &t);
}
