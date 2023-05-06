/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:54:25 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/20 16:25:04 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*ret;

	if (!n)
		return (dst);
	ret = dst;
	while (n && *src)
	{
		*dst++ = *src++;
		--n;
	}
	while (n--)
		*dst++ = 0;
	return (ret);
}
