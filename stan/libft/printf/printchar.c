/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:23:10 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/12 23:42:27 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

/*
 *	TODO _wcrtomb()
 */
static int	print_char_long(t_printf *spec, va_list vargs, int *cnt)
{
	(void) spec;
	(void) vargs;
	(void) cnt;
	return (0);
}

static int	print_char_short(t_printf *spec, va_list vargs, int *cnt)
{
	char	*s;
	size_t	sz;

	spec->arg.as_char = va_arg(vargs, int);
	if (spec->arg.as_char != 0)
	{
		if (!ft_chrstr(spec->arg.as_char, 1, &s) || !flags_char(spec, &s))
			return (0);
		return (print_final(s, cnt, spec->fd));
	}
	if (!ft_chrstr('*', 1, &s) || !flags_char(spec, &s))
		return (0);
	sz = ft_strlen(s);
	*(ft_strchr(s, '*')) = 0;
	return (print_final_sz(s, sz, cnt, spec->fd));
}

int	print_char(t_printf *spec, va_list vargs, int *cnt)
{
	if (spec->conversion == 'c')
	{
		if (*spec->length == 0)
			return (print_char_short(spec, vargs, cnt));
		if (!ft_strcmp(spec->length, "l"))
			return (print_char_long(spec, vargs, cnt));
	}
	if (spec->conversion == 'C')
		return (print_char_long(spec, vargs, cnt));
	return (0);
}
