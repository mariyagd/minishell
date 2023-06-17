/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:31:25 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:30:48 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/get_next_line.h"

char	*get_next_line_maxopen(int fd)
{
	static char		*line[OPEN_MAX];
	char			*result;
	int				error;

	error = check_errors(fd, &line[fd]);
	if (error == 0)
		return (NULL);
	line[fd] = read_fd(line[fd], fd, &error);
	if (error == -1 || (error == 0 && !*line[fd]))
	{
		free(line[fd]);
		line[fd] = 0;
		return (NULL);
	}
	if (!line[fd])
		return (NULL);
	result = create_result(line[fd]);
	if (!result)
	{
		line[fd] = 0;
		free(line[fd]);
	}
	line[fd] = create_nextline(result, line[fd]);
	return (result);
}
