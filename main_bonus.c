#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <libc.h>

int main(int argc, char **argv)
{
	int *fd;
	char *line;
	int i;
	int ret;
	i = 0;
	fd = malloc(sizeof(int) * (argc - 1));
	for (i = 1; i <= argc; i++)
		fd[i - 1] = open(argv[i], O_RDONLY);
	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd[i % (argc - 1)], &line);
		printf("fd = %d : %d => \"%s\"\n", fd[i % (argc - 1)], ret, line);
		if (ret != -1)
			free(line);
		i++;
	}
	free(fd);
	system("leaks a.out");
	return (0);
}
