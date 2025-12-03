#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	fd;
	char	buffer[1];

	i = 0;
	fd = open(av[1], O_RDONLY);
	int rd = read(fd, buffer, 1);
	while (rd > 0)
	{
		printf("%c", buffer[0] - i);
		rd = read(fd, buffer, 1);
		i++;
	}
}
