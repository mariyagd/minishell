/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightpadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:20:20 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/11 19:29:52 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	_rightpadd(char **p, char c, size_t n)
{
	char	*s;

	if (n == 0)
		return (1);
	s = ft_malloc(sizeof(char) * (ft_strlen(*p) + n + 1));
	if (!s)
	{
		ft_free(*p);
		return (0);
	}
	ft_strcatchr(ft_stpcpy(s, *p), c, n);
	ft_free(*p);
	*p = s;
	return (1);
}
