#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"
#include "stdlib.h"
#include "errno.h"

void	start(char *s)
{
	printf("-----Start %s-----\n", s);
}

void	end(char *s)
{
	printf("-----End %s-----\n", s);
}

void hello();

int min(int a, int b);

int ft_strlen(const char *s);

int ft_strcmp(const char *s1,const char *s2);

char	*ft_strcpy(char *dst, const char *src);

size_t	ft_write(int fd, void *buf, size_t count);

size_t	ft_read(int fd, void *buf, size_t count);

char	*ft_strdup(const char *s);

void	test_strlen(char *s)
{
	start(s);
	printf("ft (%i), std (%i)\n", ft_strlen(""), strlen(""));
	printf("ft (%i), std (%i)\n", ft_strlen("a"), strlen("a"));
	printf("ft (%i), std (%i)\n", ft_strlen("asddasdsaddddasdas"), strlen("asddasdsaddddasdas"));
	printf("ft (%i), std (%i)\n", ft_strlen("Hello world!\n"), strlen("Hello world!\n"));
	printf("ft (%i), std (%i)\n", ft_strlen("asd"), strlen("asd"));
	printf("ft (%i), std (%i)\n", ft_strlen("as"), strlen("as"));
	printf("ft (%i), std (%i)\n", ft_strlen("asda"), strlen("asda"));
	end(s);
}

void	test_strcmp(char *s)
{
	start(s);
	printf("ft (%i), std (%i)\n", ft_strcmp("", ""), strcmp("", ""));
	printf("ft (%i), std (%i)\n", ft_strcmp("a", "a"), strcmp("a", "a"));
	printf("ft (%i), std (%i)\n", ft_strcmp("b", "a"), strcmp("b", "a"));
	printf("ft (%i), std (%i)\n", ft_strcmp("a", "b"), strcmp("a", "b"));
	printf("ft (%i), std (%i)\n", ft_strcmp("c", "a"), strcmp("c", "a"));
	printf("ft (%i), std (%i)\n", ft_strcmp("aaaa", "aaaa"), strcmp("aaaa", "aaaa"));
	printf("ft (%i), std (%i)\n", ft_strcmp("aaaa", "aaa"), strcmp("aaaa", "aaa"));
	printf("ft (%i), std (%i)\n", ft_strcmp("aa", "a"), strcmp("aa", "a"));
	printf("ft (%i), std (%i)\n", ft_strcmp("aa", ""), strcmp("aa", ""));
	printf("ft (%i), std (%i)\n", ft_strcmp("aa", "a"), strcmp("aa", "a"));
	printf("ft (%i), std (%i)\n", ft_strcmp("b", "a"), strcmp("b", "a"));
	printf("ft (%i), std (%i)\n", ft_strcmp("c", "a"), strcmp("c", "a"));
	printf("ft (%i), std (%i)\n", ft_strcmp("abcdefg", "abc"), strcmp("abcdefg", "abc"));
	printf("ft (%i), std (%i)\n", ft_strcmp("abc", "abc"), strcmp("abc", "abc"));
	printf("ft (%i), std (%i)\n", ft_strcmp("abc", "abcdefg"), strcmp("abc", "abcdefg"));
	printf("ft (%i), std (%i)\n", ft_strcmp("", "a"), strcmp("", "a"));
	printf("ft (%i), std (%i)\n", ft_strcmp("a", ""), strcmp("a", ""));
	end(s);
}

void	unit_test_strcpy(char *cs1, char *cs2)
{
	char *s1 = strdup(cs1);
	char *s2 = strdup(cs2);
	char *s3 = strdup(cs1);
	char *s4 = strdup(cs2);
	printf("\nft (%s), std (%s)\n", ft_strcpy(s1, s2), strcpy(s3, s4));
	printf("ft (%s / %s), std (%s / %s)\n", s1, s2, s3, s4);
	free(s1);
	free(s2);
	free(s3);
	free(s4);
}

void	test_strcpy(char *s)
{
	start(s);
	unit_test_strcpy("a\0\0\0", "b\0\0\0");
	unit_test_strcpy("Hello", "WWWWW");
	unit_test_strcpy("AAAAA", "Hello");
	unit_test_strcpy("", "");
	unit_test_strcpy("ABC", "");
	unit_test_strcpy("", "ABC");
	end(s);
}

void	unit_test_write(int fd, int ft_fd, char *str)
{
	size_t a = write(fd, str, strlen(str));
	size_t b = ft_write(ft_fd, str, strlen(str));
	printf("ft(%lu), std(%lu)\n", b, a);
	printf("Errno: %i\n", errno);
}

void	test_write(char *s)
{
	start(s);
	int fd = open("write_out.txt", O_RDWR | O_CREAT, S_IRUSR
		| S_IROTH | S_IWUSR);
	int ft_fd = open("ft_write_out.txt", O_RDWR | O_CREAT, S_IRUSR
		| S_IROTH | S_IWUSR);


	unit_test_write(fd, -1, "ASD\n");
	unit_test_write(fd, ft_fd, "Hello\n");
	unit_test_write(fd, ft_fd, "second line\n");
	unit_test_write(fd, ft_fd, "\n");
	unit_test_write(fd, ft_fd, "4 End\n");
	
	close(fd);
	close(ft_fd);
	end(s);
}

void	unit_test_read(int fd, int ft_fd)
{
	char *buf = strdup(" ");
	char *ft_buf = strdup(" ");
	size_t a = 1;
	size_t b = 1;
	printf("std\n");
	while (a != 0)
	{
		a = read(fd, buf, strlen(buf));
		printf("%s", buf);
	}
	printf("ft\n");
	while (b != 0)
	{
		b = ft_read(ft_fd, ft_buf, strlen(ft_buf));
		printf("%s", ft_buf);
	}
	free (buf);
	free (ft_buf);
}

void	test_read(char *s)
{
	start(s);
	int fd = open("write_out.txt", O_RDWR | O_CREAT, S_IRUSR
		| S_IROTH | S_IWUSR);
	int ft_fd = open("ft_write_out.txt", O_RDWR | O_CREAT, S_IRUSR
		| S_IROTH | S_IWUSR);


	unit_test_read(fd, ft_fd);
	
	close(fd);
	close(ft_fd);
	end(s);
}

void	unit_test_strdup(char *s)
{
	char *s1 = ft_strdup(s);
	char *s2 = strdup(s);
	printf("ft (%s), std (%s)\n", s1, s2);
	free(s1);
	free (s2);
}

void	test_strdup(char *s)
{
	start(s);
	unit_test_strdup("Hello");
	unit_test_strdup("");
	unit_test_strdup("a");
	unit_test_strdup("It is a string.");	
	end(s);
}

int main()
{
	test_strlen("ft_strlen");
	test_strcmp("ft_strcmp");
	test_strcpy("ft_strcpy");
	test_write("ft_write");
	test_read("ft_read");
	test_strdup("ft_strdup");
	return (0);
}