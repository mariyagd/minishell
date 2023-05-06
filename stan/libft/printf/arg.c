/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:21:52 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 17:01:34 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

/*
 *	TODO
 */
int	arg_is_zero(t_printf *spec)
{
	if (spec->conversion == 'c')
	{
		if (spec->arg.as_char == 0)
			return (1);
	}
	if (ft_strchr("di", spec->conversion))
	{
		if (spec->arg.as_int == 0)
			return (1);
	}
	if (ft_strchr("uoxX", spec->conversion))
	{
		if (spec->arg.as_uint == 0)
			return (1);
	}
	if (ft_strchr("aAeEfFgG", spec->conversion))
	{
		if (spec->arg.as_double == 0)
			return (1);
	}
	return (0);
}

int	arg_is_negative(t_printf *spec)
{
	if (spec->conversion == 'c')
	{
		if (spec->arg.as_char < 0)
			return (1);
	}
	if (ft_strchr("di", spec->conversion))
	{
		if (spec->arg.as_int < 0)
			return (1);
	}
	if (ft_strchr("uoxX", spec->conversion))
		return (0);
	if (ft_strchr("aAeEfFgG", spec->conversion))
	{
		if (spec->arg.as_double < 0)
			return (1);
	}
	return (0);
}
