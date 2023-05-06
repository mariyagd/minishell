/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:04:19 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 17:45:25 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_append(char **sp, const char *suffix)
{
	char	*p;
	char	*s;
	char	*p2;

	if (!*suffix)
		return (1);
	p = ft_malloc(sizeof(char) * (ft_strlen(*sp) + ft_strlen(suffix) + 1));
	if (!p)
	{
		ft_free(*sp);
		*sp = 0;
		return (0);
	}
	p2 = p;
	s = *sp;
	while (*s)
		*p++ = *s++;
	while (*suffix)
		*p++ = *suffix++;
	*p = 0;
	ft_free(*sp);
	*sp = p2;
	return (1);
}
