/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftpadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:29:12 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/11 19:21:53 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static int	_leftpaddskip2(char **p, char c, size_t n, char skipx)
{
	char	*s;

	s = ft_malloc(sizeof(char) * (ft_strlen(*p) + n + 1));
	if (!s)
	{
		ft_free(*p);
		return (0);
	}
	s[0] = '0';
	s[1] = skipx;
	s[2] = 0;
	ft_strcatchr(s, c, n);
	ft_strcat(s, &(*p)[2]);
	ft_free(*p);
	*p = s;
	return (1);
}

static int	_leftpaddskip(char **p, char c, size_t n, char skipchar)
{
	char	*s;

	s = ft_malloc(sizeof(char) * (ft_strlen(*p) + n + 1));
	if (!s)
	{
		ft_free(*p);
		return (0);
	}
	s[0] = skipchar;
	s[1] = 0;
	ft_strcatchr(s, c, n);
	ft_strcat(s, &(*p)[1]);
	ft_free(*p);
	*p = s;
	return (1);
}

int	_leftpadd(char **p, char c, size_t n)
{
	char	*s;

	if (n == 0)
		return (1);
	if (c == '0')
	{
		if (**p == '0' && (*p)[1] && ft_strchr("xX", (*p)[1]))
			return (_leftpaddskip2(p, c, n, (*p)[1]));
		if (ft_strchr("+- ", **p))
			return (_leftpaddskip(p, c, n, **p));
	}
	s = ft_malloc(sizeof(char) * (ft_strlen(*p) + n + 1));
	if (!s)
	{
		ft_free(*p);
		return (0);
	}
	*s = 0;
	ft_strcatchr(s, c, n);
	ft_strcat(s, *p);
	ft_free(*p);
	*p = s;
	return (1);
}
