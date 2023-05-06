/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:42:16 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/30 16:49:36 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	sz;

	if (!*accept)
		return (0);
	sz = 0;
	while (*s)
	{
		if (!ft_strchr(accept, *s++))
			return (sz);
		++sz;
	}
	return (sz);
}
