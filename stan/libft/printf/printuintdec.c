/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuintdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:05:10 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/13 18:12:31 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static int	print_uchar(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_uchar = va_arg(vargs, unsigned int);
	ft_ulltoa(spec->arg.as_uchar, buf);
	if (!ft_strnew(&s, buf) || !flags_uint(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

static int	print_ushort(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_ushort = va_arg(vargs, unsigned int);
	ft_ulltoa(spec->arg.as_ushort, buf);
	if (!ft_strnew(&s, buf) || !flags_uint(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

static int	print_ulonglong(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_ulonglong = va_arg(vargs, unsigned long long);
	ft_ulltoa(spec->arg.as_ulonglong, buf);
	if (!ft_strnew(&s, buf) ||!flags_uint(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

static int	print_ulong(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[21];
	char	*s;

	spec->arg.as_ulong = va_arg(vargs, unsigned long);
	ft_ulltoa(spec->arg.as_ulong, buf);
	if (!ft_strnew(&s, buf) || !flags_uint(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

int	print_uint_dec(t_printf *spec, va_list vargs, int *cnt)
{
	if (*spec->length == 0)
		return (print_uint_uint(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "hh"))
		return (print_uchar(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "h"))
		return (print_ushort(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "ll"))
		return (print_ulonglong(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "l"))
		return (print_ulong(spec, vargs, cnt));
	if (!ft_strcmp(spec->length, "z"))
		return (print_uint_size_t(spec, vargs, cnt));
	return (0);
}
