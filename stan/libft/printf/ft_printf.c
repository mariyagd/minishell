/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:08:14 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/12 01:39:01 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static int	printspec(int fd, char **s, va_list vargs, int *cnt)
{
	t_printf	spec;
	char		*next;

	next = load(fd, &spec, *s + 1);
	if (next)
	{
		if (!print(&spec, vargs, cnt))
			return (0);
		*s = next;
		return (1);
	}
	return (0);
}

static int	printstr(int fd, char **s, int *cnt)
{
	char	*p;
	size_t	sz;

	p = ft_strchr(*s, '%');
	if (!p)
		sz = ft_strlen(*s);
	else
		sz = p - *s;
	if (!ft_putstr_sz(*s, sz, fd))
		return (0);
	*cnt += sz;
	*s += sz;
	return (1);
}

int	ft_vdprintf(int fd, const char *s, va_list vargs)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (!printspec(fd, (char **) &s, vargs, &cnt))
				return (-1);
		}
		else
		{
			if (!printstr(fd, (char **) &s, &cnt))
				return (-1);
		}
	}
	return (cnt);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list	vargs;
	int		cnt;

	va_start(vargs, s);
	cnt = ft_vdprintf(fd, s, vargs);
	va_end(vargs);
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	vargs;
	int		cnt;

	va_start(vargs, s);
	cnt = ft_vdprintf(1, s, vargs);
	va_end(vargs);
	return (cnt);
}
