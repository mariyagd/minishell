/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcount2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:38:40 by pmarquis          #+#    #+#             */
/*   Updated: 2022/10/30 12:45:05 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	print_count_char(t_printf *spec, va_list vargs, int *cnt)
{
	signed char	*c;

	(void) spec;
	c = va_arg(vargs, signed char *);
	*c = *cnt;
	return (1);
}

int	print_count_short(t_printf *spec, va_list vargs, int *cnt)
{
	short	*sh;

	(void) spec;
	sh = va_arg(vargs, short *);
	*sh = *cnt;
	return (1);
}

int	print_count_int(t_printf *spec, va_list vargs, int *cnt)
{
	int	*i;

	(void) spec;
	i = va_arg(vargs, int *);
	*i = *cnt;
	return (1);
}
