#include <stdio.h>
#include <string.h>
#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}

int main(){
	char array[10] = "123456789";
	char array2[10] = "123456789";
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	ft_memcpy(((void *)0), "segfaulter tu dois", 17);

	for(int i = 0; i < 10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	memcpy(arr2 + 1, arr2, 10);

	for(int i = 0; i < 10; i++){
		printf("%d ", arr2[i]);
	}
	printf("\n");
	
	return 0;
}
