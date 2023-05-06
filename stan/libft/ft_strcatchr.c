/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:32:28 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/19 18:13:35 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// append char 'c' to string 'dest', 'n' times
// dest must have the required memory for n+1 chars

char	*ft_strcatchr(char *dest, char c, size_t n)
{
	char	*p;

	if (!n)
		return (dest);
	p = dest;
	while (*p)
		++p;
	while (n--)
		*p++ = c;
	*p = 0;
	return (dest);
}
