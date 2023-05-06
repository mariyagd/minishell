/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:58:41 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/13 18:09:14 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

/*
 *	/!\ gcc/linux => (nil)
 *	    clang/mac => 0x0
 */

#ifdef LINUX

int	print_pointer(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[17];
	char	*s;

	spec->arg.as_void_p = va_arg(vargs, void *);
	if (!spec->arg.as_void_p)
	{
		if (!ft_strnew(&s, "(nil)") || !flags_pointer(spec, &s))
			return (0);
	}
	else
	{
		ft_ulltoa_hex((unsigned long long) spec->arg.as_void_p, buf);
		if (!ft_strnew(&s, buf)
			|| !ft_prepend(&s, "0x") || !flags_pointer(spec, &s))
			return (0);
	}
	return (print_final(s, cnt, spec->fd));
}

#else // DARWIN

int	print_pointer(t_printf *spec, va_list vargs, int *cnt)
{
	char	buf[17];
	char	*s;

	spec->arg.as_void_p = va_arg(vargs, void *);
	ft_ulltoa_hex((unsigned long long) spec->arg.as_void_p, buf);
	if (!ft_strnew(&s, buf)
		|| !ft_prepend(&s, "0x") || !flags_pointer(spec, &s))
		return (0);
	return (print_final(s, cnt, spec->fd));
}

#endif
