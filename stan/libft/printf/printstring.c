/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:02:40 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/09 16:18:46 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

/*
 *	TODO _wcrtomb()
 */
static int	print_string_wchar(t_printf *spec, va_list vargs, int *cnt)
{
	(void) spec;
	(void) vargs;
	(void) cnt;
	return (0);
}

static int	print_string_char(t_printf *spec, va_list vargs, int *cnt)
{
	char	*s;

	spec->arg.as_char_p = va_arg(vargs, char *);
	if (spec->arg.as_char_p)
		s = ft_strdup(spec->arg.as_char_p);
	else
		s = ft_strdup("(null)");
	if (!s || !flags_string(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

int	print_string(t_printf *spec, va_list vargs, int *cnt)
{
	if (spec->conversion == 's')
	{
		if (*spec->length == 0)
			return (print_string_char(spec, vargs, cnt));
		else if (!ft_strcmp(spec->length, "l"))
			return (print_string_wchar(spec, vargs, cnt));
	}
	if (spec->conversion == 'S')
		return (print_string_wchar(spec, vargs, cnt));
	return (0);
}
