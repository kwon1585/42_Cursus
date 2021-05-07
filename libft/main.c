#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	src_i;
	size_t	cat_i;

	dst_i = 0;
	src_i = 0;
	while (*(dst + dst_i))
		dst_i++;
	cat_i = dst_i;
	while (*(src + src_i) && cat_i + 1 < dstsize)
		*(dst + cat_i++) = *(src + src_i++);
	*(dst + cat_i) = '\0';
	src_i = 0;
	while (*(src + src_i) != '\0')
		src_i++;
	if (dstsize < dst_i)
		return (src_i + dstsize);
	else
		return (src_i + dst_i);
}

int main(){
	int ans;
	char *dest = (char *)malloc(sizeof(*dest) * 15);
	memset(dest, 'r', 15);
	ans = strlcat(dest, "lorem ipsum dolor sit amet", 5);
	printf("%s %d\n", dest, ans);
	ans = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
	printf("%s %d\n", dest, ans);
	return 0;
}
