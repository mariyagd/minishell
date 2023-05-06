/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:38:54 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/20 16:22:07 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (s1 == s2 || !n)
		return (0);
	while (n--)
	{
		if (*(unsigned char *)s1 == *(unsigned char *)s2 && n)
		{
			(void)(unsigned char *)++s1;
			(void)(unsigned char *)++s2;
		}
		else
			break ;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
