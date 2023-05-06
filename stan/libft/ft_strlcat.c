/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:41:09 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/28 19:43:33 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			sz;
	size_t			srclen;
	const size_t	tot = ft_strlen(dst) + ft_strlen2(src, &srclen);

	if (!size)
		return (srclen);
	sz = size;
	while (*dst && sz)
	{
		++dst;
		--sz;
	}
	if (!sz)
		return (size + srclen);
	while (*src && --sz)
		*dst++ = *src++;
	*dst = 0;
	if (!sz)
		return (tot);
	return (size - sz);
}
