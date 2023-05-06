/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:25:54 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/17 00:51:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_getnext.h"

#define PAGESZ	64

static int	_free(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
		ft_free(ret[i++]);
	ft_free(ret);
	return (0);
}

static int	_realloc(char ***ret, size_t *page)
{
	char	**buf;

	buf = ft_calloc(PAGESZ * ((*page) + 1), sizeof(char *));
	if (!buf)
		return (_free(*ret));
	ft_memcpy(buf, *ret, sizeof(char *) * PAGESZ * (*page));
	ft_free(*ret);
	*ret = buf;
	++(*page);
	return (1);
}

char	**ft_getfile(int fd)
{
	char	**ret;
	size_t	page;
	size_t	i;
	char	*line;

	ret = ft_calloc(PAGESZ, sizeof(char *));
	if (!ret)
		return (0);
	page = 1;
	i = 0;
	line = ft_getnextline(fd);
	while (line)
	{
		ret[i++] = line;
		if (i == (PAGESZ * page) - 1)
		{
			if (!_realloc(&ret, &page))
				return (0);
		}
		line = ft_getnextline(fd);
	}
	return (ret);
}
