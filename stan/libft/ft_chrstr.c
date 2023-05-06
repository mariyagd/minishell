/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:31:20 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/19 18:03:18 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// make a string with char 'c', of size 'n'
// returned string must be freed

int	ft_chrstr(char c, size_t n, char **ret)
{
	register size_t	i;
	char			*p;

	p = ft_malloc(sizeof(char) * (n + 1));
	if (!p)
		return (0);
	*ret = p;
	i = 0;
	while (i++ < n)
		*p++ = c;
	*p = 0;
	return (1);
}
