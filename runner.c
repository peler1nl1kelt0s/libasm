#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char *ft_strcpy(char *dest, const char *src);
int ft_strlen(const char *s);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

int main(void)
{
	printf("=== ft_strcpy TEST ===\n");
	char dst[50];
	ft_strcpy(dst, "hello world");
	printf("strcpy result: \"%s\"\n\n", dst);

	printf("=== ft_strlen TEST ===\n");
	printf("strlen(\"hello\") = %d\n", ft_strlen("hello"));
	printf("strlen(\"\") = %d\n\n", ft_strlen(""));

	printf("=== ft_strcmp TEST ===\n");
	printf("strcmp(\"abc\", \"abd\") = %d\n", ft_strcmp("abc", "abd"));
	printf("strcmp(\"abc\", \"abc\") = %d\n", ft_strcmp("abc", "abc"));
	printf("strcmp(\"xyz\", \"xya\") = %d\n\n", ft_strcmp("xyz", "xya"));

	printf("=== ft_write TEST ===\n");
	ssize_t written = ft_write(1, "ft_write output\n", 16);
	printf("ft_write returned: %zd\n\n", written);

	printf("=== ft_read TEST ===\n");
	int fd = open("test.txt", O_RDONLY);
	if (fd >= 0)
	{
		char buff[100];
		ssize_t nread = ft_read(fd, buff, 50);
		printf("ft_read returned: %zd\n", nread);
		if (nread > 0)
		{
			buff[nread] = '\0';
			printf("read content: \"%s\"\n", buff);
		}
		close(fd);
	}
	printf("\n");

	printf("=== ft_strdup TEST ===\n");
	char *dup = ft_strdup("duplicated string");
	if (dup)
	{
		printf("strdup result: \"%s\"\n", dup);
		free(dup);
	}

	return 0;
}