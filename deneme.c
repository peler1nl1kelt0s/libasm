#include <stdio.h>
#include <stdlib.h>

char *ft_strcpy(char *dest, const char *src);
int ft_strlen(const char *s);

int main(void)
{
	const char *src = "hello";
	char dst[16];

	ft_strcpy(dst, src);
	printf("ft_strcpy: src=\"%s\" dst=\"%s\"\n", src, dst);

	int len = ft_strlen(src);
	printf("ft_strlen: \"%s\" -> %d\n", src, len);

	return 0;
}