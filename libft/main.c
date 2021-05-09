#include "libft.h"
#include "stdio.h"
#include "string.h"

int main()
{
	int size = 8539;

	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	int ans = memcmp(d1, d2, size * sizeof(int));
	
	printf("%d", ans);
	free(d1);
	free(d2);	
}
