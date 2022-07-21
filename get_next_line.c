/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:55:04 by hboichuk          #+#    #+#             */
/*   Updated: 2022/07/21 13:41:31 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_new_line(char *storage)
{
	int		i;
	char	*s;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		s[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		s[i] = storage[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*save_previous_line(char *storage)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (storage[i])
		s[c++] = storage[i++];
	s[c] = '\0';
	free(storage);
	return (s);
}

char	*read_storage(int fd, char *storage)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(storage, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		storage = ft_strjoin(storage, buff);
	}
	free(buff);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	storage = read_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = get_new_line(storage);
	storage = save_previous_line(storage);
	return (line);
}

