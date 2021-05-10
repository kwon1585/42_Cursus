#include "libft.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char *s = "split  ||this|for|me|||||!|";
	int i = 0;
	char **result = ft_split(s, '|');

	while (*(result + i))
		printf("i : %d | %s\n", i, *(result + i++));
	free(result);
}
