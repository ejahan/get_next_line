/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:03:00 by ejahan            #+#    #+#             */
/*   Updated: 2021/01/25 21:04:56 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int		ft_static(char *s, char **line)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (ft_strchr(s, '\n') != NULL)
	{
		*line = ft_substr(s, 0, ft_strlen(s) - ft_strlen(ft_strchr(s, '\n')));
		if (line == NULL)
			return (-1);
		ft_strcpy(s, ft_strchr(s, '\n') + 1);
		return (1);
	}
	*line = ft_substr(s, 0, ft_strlen(s) - ft_strlen(ft_strchr(s, '\0')));
	if (line == NULL)
		return (-1);
	if (i >= 0)
	{
		ft_strcpy(s, ft_strchr(s, '\0'));
		return (0);
	}
	return (-1);
}

static	char	*allocate(size_t size, char *str)
{
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = size + 1;
	while (size-- > 0)
		str[size] = '\0';
	return (str);
}

static	int		ft_free(char **str, char *buffer, int j, char **line)
{
	int i;

	if (j > 0)
	{
		if (buffer)
			free(buffer);
		if ((*str))
			free((*str));
		(*str) = NULL;
		return (-1);
	}
	free(buffer);
	i = ft_static((*str), line);
	if (i == 0)
	{
		free((*str));
		(*str) = NULL;
	}
	return (i);
}

int				get_next_line(int fd, char **line)
{
	static	char	*str[1024];
	char			*buffer;
	char			*tmp;
	int				i;
	int				j;

	j = 0;
	if ((str[fd] == NULL && (str[fd] = allocate(0, str[fd])) == NULL)
		|| (buffer = malloc(BUFFER_SIZE + 1)) == NULL
		|| fd < 0 || BUFFER_SIZE < 1 || line == NULL || read(fd, buffer, 0) < 0)
		j = 1;
	while (ft_strchr(str[fd], '\n') == NULL
			&& ((i = read(fd, buffer, BUFFER_SIZE)) > 0) && j == 0)
	{
		buffer[i] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	i = ft_free(&str[fd], buffer, j, line);
	return (i);
}
