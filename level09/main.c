
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
int main(void)
{
	int fd = open("token", O_RDONLY);
	if (fd == -1)
	{
		printf("non\n");
		return 1;
	}
	int i = 0;
	while (1)
	{
		char c;
		int a = read(fd, &c, 1);
		printf("%c", c - i);
		if (a <= 0)
			break ;
		i++;
	}
	printf("\n");
	close(fd);
	return 0;
}
