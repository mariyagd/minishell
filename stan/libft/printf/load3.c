/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:13:19 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/08 03:34:23 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	flag_apostrophe(t_printf *spec, char **s)
{
	spec->apostrophe = 1;
	++(*s);
	if (**s != 0)
		return (1);
	return (0);
}

int	flag_upper_i(t_printf *spec, char **s)
{
	spec->upper_i = 1;
	++(*s);
	if (**s != 0)
		return (1);
	return (0);
}

int	load_field_width(t_printf *spec, char **s)
{
	if (ft_isdigit(**s) && **s != '0')
		*s = ft_atoi(*s, &spec->field_width);
	if (*s != 0 && **s != 0)
		return (1);
	return (0);
}

int	load_precision(t_printf *spec, char **s)
{
	if (**s == '.')
	{
		spec->precision = 1;
		if (ft_isdigit(*(*s + 1)))
		{
			*s = ft_atoi(*s + 1, &spec->_precision);
			if (spec->_precision < 0)
				spec->precision = 0;
		}
		else
		{
			spec->_precision = 0;
			*s = *s + 1;
		}
	}
	if (*s != 0 && **s != 0)
		return (1);
	return (0);
}
