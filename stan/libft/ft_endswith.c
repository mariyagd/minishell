/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:45:35 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 01:15:43 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_endswith(const char *s, const char *suffix)
{
	size_t	sz;

	if (!*s || !*suffix || ft_strlen(s) < ft_strlen2(suffix, &sz))
		return (0);
	while (*s)
		++s;
	while (*suffix)
		++suffix;
	while (sz--)
	{
		if (*--s != *--suffix)
			return (0);
	}
	return (1);
}
