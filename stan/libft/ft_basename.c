/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:05:08 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/17 23:25:15 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// inspired by POSIX version of basename

char	*ft_basename(const char *path, char *bname)
{
	char	*p;
	char	*q;

	if (!path || !*path)
		return (ft_strcpy(bname, "."));
	p = (char *) path;
	while (*p)
		++p;
	--p;
	while (*p == '/' && p > path)
		--p;
	if (p == path && *p == '/')
		return (ft_strcpy(bname, "/"));
	while (*p != '/' && p > path)
		--p;
	q = bname;
	if (*p == '/')
		++p;
	while (*p && *p != '/')
		*q++ = *p++;
	*q = 0;
	return (bname);
}
