/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:53:39 by mdanchev          #+#    #+#             */
/*   Updated: 2023/01/13 14:52:48 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/get_next_line.h"

void	prepare_forstash(char **line, char **buffer)
{
	*buffer = ft_calloc_count(BUFFER_SIZE);
	if (*line == NULL)
		*line = ft_calloc_count(0);
}

char	*ft_join(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*stash;

	if (!line || !buffer)
		return (NULL);
	i = ft_strlen_int(line);
	j = ft_strlen_int(buffer);
	stash = malloc((i + j + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		stash[i] = line[i];
		i++;
	}
	while (buffer[j] != '\0')
		stash[i++] = buffer[j++];
	stash[i] = '\0';
	free(line);
	return (stash);
}

char	*ft_calloc_count(int count)
{
	char	*string;
	int		i;

	i = 0;
	string = malloc((count + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (i <= count)
	{
		string[i] = '\0';
		i++;
	}
	return (string);
}

int	ft_strlen_int(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

int	there_is_n(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}
