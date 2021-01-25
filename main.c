/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:43:14 by ejahan            #+#    #+#             */
/*   Updated: 2021/01/20 10:54:52 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	int ret;
	int i;
	char *line;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	i = 0;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d -> [%s]\n", i, line);
		free(line);
		i++;
	}
	printf("RET: %d\n", ret);
	free(line);
	close(fd);
	system("leaks a.out");
	return (0);
}
