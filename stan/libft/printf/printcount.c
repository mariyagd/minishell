/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:23:20 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 17:13:09 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static int	print_count_longlong(t_printf *spec, va_list vargs, int *cnt)
{
	long long	*ll;

	(void) spec;
	ll = va_arg(vargs, long long *);
	*ll = *cnt;
	return (1);
}

static int	print_count_long(t_printf *spec, va_list vargs, int *cnt)
{
	long	*l;

	(void) spec;
	l = va_arg(vargs, long *);
	*l = *cnt;
	return (1);
}

static int	print_count_ptrdiff_t(t_printf *spec, va_list vargs, int *cnt)
{
	ptrdiff_t	*p;

	(void) spec;
	p = va_arg(vargs, ptrdiff_t *);
	*p = *cnt;
	return (1);
}

static int	print_count_size_t(t_printf *spec, va_list vargs, int *cnt)
{
	size_t	*sz;

	(void) spec;
	sz = va_arg(vargs, size_t *);
	*sz = *cnt;
	return (1);
}

int	print_count(t_printf *spec, va_list vargs, int *cnt)
{
	if (*spec->length == 0)
		return (print_count_int(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "hh"))
		return (print_count_char(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "h"))
		return (print_count_short(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "l"))
		return (print_count_long(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "ll"))
		return (print_count_longlong(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "t"))
		return (print_count_ptrdiff_t(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "z"))
		return (print_count_size_t(spec, vargs, cnt));
	return (0);
}
