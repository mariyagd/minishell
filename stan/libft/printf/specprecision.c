/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specprecision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:00:18 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/08 20:50:25 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static int	spec_precision_int(t_printf *spec, char **p)
{
	size_t	sz;

	sz = ft_strlen(*p);
	if (!arg_is_negative(spec) && spec->_precision > (int)sz)
	{
		if (!_leftpadd(p, '0', spec->_precision - sz))
			return (0);
	}
	else if (arg_is_negative(spec) && spec->_precision > (int)(sz - 1))
	{
		if (!_leftpadd(p, '0', spec->_precision - (sz - 1)))
			return (0);
	}
	return (1);
}

static int	spec_precision_uint(t_printf *spec, char **p)
{
	size_t	sz;

	sz = ft_strlen(*p);
	if (spec->_precision > (int)sz)
	{
		if (!_leftpadd(p, '0', spec->_precision - sz))
			return (0);
	}
	return (1);
}

static int	spec_precision_string(t_printf *spec, char **p)
{
	ft_strcut(*p, spec->_precision);
	return (1);
}

int	spec_precision(t_printf *spec, char **p)
{
	if (ft_strchr("di", spec->conversion))
		return (spec_precision_int(spec, p));
	if (ft_strchr("ouxX", spec->conversion))
		return (spec_precision_uint(spec, p));
	if (spec->conversion == 's')
		return (spec_precision_string(spec, p));
	return (0);
}
