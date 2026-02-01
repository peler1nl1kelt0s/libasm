#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *ft_strcpy(char *dest, const char *src);
int ft_strlen(const char *s);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
int main(void)
{
	// DATAS
	const char *src = "hello";
	char dst[16];
	int fd = open("test.txt", O_RDONLY);
	char buff[1024];

	// TESTİNG FUNCTİONS
	ft_strcpy(dst, src);
	printf("ft_strcpy: src=\"%s\" dst=\"%s\"\n", src, dst);

	printf("ft_strlen: \"%s\" -> %d\n", src, ft_strlen(src));

	printf("ft_strcmp: %d\n", ft_strcmp("elma","elmb"));

	printf("ft_write: %zd\n", ft_write(1,"elma\n",5));

	// printf("ft_read: %zd\n", ft_read(fd, buff, 3));
	// close(fd);
	ssize_t n = read(fd, buff, 3);
	printf("read: %zd\n", n);
	if (n >= 0)
		buff[n] = '\0';
	printf("buffer: %s\n", buff);
	close(fd);
	return 0;
}