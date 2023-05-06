/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:05:08 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/17 23:59:03 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dirname(const char *path, char *dname)
{
	char	*p;

	if (!path || !*path)
		return (ft_strcpy(dname, "."));
	p = (char *) path;
	while (*p)
		++p;
	--p;
	while (*p == '/' && p > path)
		--p;
	if (p == path && *p == '/')
		return (ft_strcpy(dname, "/"));
	while (*p != '/' && p > path)
		--p;
	if (p == path)
	{
		if (*p != '/')
			return (ft_strcpy(dname, "."));
		return (ft_strcpy(dname, "/"));
	}
	ft_strncpy(dname, path, p - path);
	dname[p - path] = 0;
	return (dname);
}
