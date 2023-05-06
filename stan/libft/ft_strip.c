/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:51:24 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/12 21:08:15 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strip(const char *s)
{
	char	*p;
	char	*q;
	char	*end;
	char	*ret;

	p = ft_strdup(s);
	if (!p)
		return (0);
	q = p;
	while (*q && ft_isspace(*q))
		++q;
	end = ft_strchr(p, 0) - 1;
	while (end > q && ft_isspace(*end))
		*end-- = 0;
	ret = ft_strdup(q);
	ft_free(p);
	return (ret);
}
