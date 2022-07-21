/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:08:03 by hboichuk          #+#    #+#             */
/*   Updated: 2022/07/10 17:38:33 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if (c == 0)
	{
		return ((char *)&s[ft_strlen(s)]);
	}
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (string == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			string[i] = s1[i];
	while (s2[j] != '\0')
		string[i++] = s2[j++];
	string[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (string);
}
