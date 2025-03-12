/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diespino <diespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:00:17 by diespino          #+#    #+#             */
/*   Updated: 2025/03/05 13:59:31 by diespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// get_next_line
char	*get_next_line(int fd);
char	*read_to_n(int fd, char *all_readed);
char	*get_a_line(char *all_readed);
char	*new_line(char *all_readed);

// utils
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *all_readed, char *buff);

#endif
