/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diespino <diespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:04:52 by diespino          #+#    #+#             */
/*   Updated: 2025/03/06 15:59:49 by diespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)s);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *all_readed, char *buff)
{
	int		i;
	int		len_readed;
	char	*result;

	if (!all_readed)
	{
		all_readed = malloc(sizeof(char) * 1);
		all_readed[0] = '\0';
	}
	if (!all_readed || !buff)
		return (NULL);
	len_readed = ft_strlen(all_readed);
	result = malloc(sizeof(char) * (len_readed + ft_strlen(buff) + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (all_readed[++i])
		result[i] = all_readed[i];
	i = -1;
	while (buff[++i])
		result[len_readed + i] = buff[i];
	result[len_readed + i] = '\0';
	free(all_readed);
	return (result);
}
