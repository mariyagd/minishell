/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:10:32 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/20 16:22:31 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*ret;

	if (dst == src || !n)
		return (dst);
	if ((unsigned char *)dst < (unsigned char *)src
		|| (unsigned char *)dst > (unsigned char *)src + (n - 1))
		return (ft_memcpy(dst, src, n));
	ret = dst;
	dst += n - 1;
	src += n - 1;
	while (n--)
		*((unsigned char *)dst--) = *((unsigned char *)src--);
	return (ret);
}
