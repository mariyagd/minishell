/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spechash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:19:50 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 01:24:33 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	spec_hash(t_printf *spec, char **p)
{
	if (spec->conversion == 'x')
	{
		if (!arg_is_zero(spec) && !ft_prepend(p, "0x"))
			return (0);
		return (1);
	}
	if (spec->conversion == 'X')
	{
		if (!arg_is_zero(spec) && !ft_prepend(p, "0X"))
			return (0);
		return (1);
	}
	if (spec->conversion == 'o')
	{
		if (**p != '0' && !ft_prepend(p, "0"))
			return (0);
		return (1);
	}
	if (spec->conversion == 'f')
	{
		if (!ft_strchr(*p, '.') && !ft_append(p, "."))
			return (0);
		return (1);
	}
	return (0);
}
