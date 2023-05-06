/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 02:15:06 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/20 16:23:33 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, char c)
{
	if (!c)
	{
		while (*s)
			++s;
		return ((char *) s);
	}
	while (*s)
	{
		if (*s == c)
			return ((char *) s);
		++s;
	}
	return (0);
}
