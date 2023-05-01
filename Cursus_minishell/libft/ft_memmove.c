/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:57:27 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/10 19:22:23 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*destin;
	char	*source;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	destin = (char *)dst;
	source = (char *)src;
	if (destin > source)
	{
		while (len-- > 0)
			destin[len] = source[len];
	}
	else
	{
		while (i < len)
		{
			destin[i] = source[i];
			i++;
		}
	}
	return (destin);
}
