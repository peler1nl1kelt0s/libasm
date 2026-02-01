#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strcpy(char *dest, const char *src);
int ft_strlen(const char *s);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);

int main(void)
{
	const char *src = "hello";
	char dst[16];

	ft_strcpy(dst, src);
	printf("ft_strcpy: src=\"%s\" dst=\"%s\"\n", src, dst);

	int len = ft_strlen(src);
	printf("ft_strlen: \"%s\" -> %d\n", src, len);

	printf("ft_strcmp: %d\n", ft_strcmp("elma","elmb"));

	printf("ft_write: %zd\n", ft_write(1,"elma\n",4));
	return 0;
}