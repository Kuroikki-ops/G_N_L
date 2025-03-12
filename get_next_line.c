/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diespino <diespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:58:45 by diespino          #+#    #+#             */
/*   Updated: 2025/03/06 15:51:00 by diespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_to_n(int fd, char *all_readed)
{
	char	*buff;
	int		readed;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_strchr(all_readed, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			free(all_readed);
			return (NULL);
		}
		buff[readed] = '\0';
		all_readed = ft_strjoin(all_readed, buff);
	}
	free(buff);
	return (all_readed);
}

char	*get_a_line(char *all_readed)
{
	char	*line;
	int		i;

	i = 0;
	if (!all_readed[i])
		return (NULL);
	while (all_readed[i] && all_readed[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (all_readed[i] && all_readed[i] != '\n')
	{
		line[i] = all_readed[i];
		i++;
	}
	if (all_readed[i] == '\n')
	{
		line[i] = all_readed[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_line(char *all_readed)
{
	int		i;
	int		j;
	char	*left_rd;

	i = 0;
	while (all_readed[i] && all_readed[i] != '\n')
		i++;
	if (!all_readed[i])
	{
		free(all_readed);
		return (NULL);
	}
	left_rd = malloc(sizeof(char) * (ft_strlen(all_readed) - i + 1));
	if (!left_rd)
		return (NULL);
	i++;
	j = 0;
	while (all_readed[i])
		left_rd[j++] = all_readed[i++];
	left_rd[j] = '\0';
	free(all_readed);
	return (left_rd);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*all_readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	all_readed = read_to_n(fd, all_readed);
	if (!all_readed)
		return (NULL);
	line = get_a_line(all_readed);
	all_readed = new_line(all_readed);
	return (line);
}
