/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:09:43 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/04 18:44:32 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	flag_hash(t_printf *spec, char **s)
{
	spec->hash = 1;
	++(*s);
	if (**s != 0)
		return (1);
	return (0);
}

int	flag_zero(t_printf *spec, char **s)
{
	if (!spec->minus)
		spec->zero = 1;
	++(*s);
	if (**s != 0)
		return (1);
	return (0);
}

int	flag_minus(t_printf *spec, char **s)
{
	spec->minus = 1;
	spec->zero = 0;
	++(*s);
	if (**s != 0)
		return (1);
	return (0);
}

int	flag_space(t_printf *spec, char **s)
{
	if (!spec->plus)
		spec->space = 1;
	++(*s);
	if (**s != 0)
		return (1);
	return (0);
}

int	flag_plus(t_printf *spec, char **s)
{
	spec->plus = 1;
	spec->space = 0;
	++(*s);
	if (**s != 0)
		return (1);
	return (0);
}
