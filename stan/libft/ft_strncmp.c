/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:48:18 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/28 19:43:33 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == s2 || !n)
		return (0);
	while (n--)
	{
		if (*s1 && (*s1 == *s2) && n)
		{
			++s1;
			++s2;
		}
		else
			break ;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
