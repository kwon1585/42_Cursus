#include "libft.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char *s = "abcdef";
	char *p = ft_strchr(s, 'd');
	
	printf("%p %p %d", s, p, (int)(s - p));
}
