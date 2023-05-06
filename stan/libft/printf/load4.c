/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:13:03 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/08 03:35:02 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static int	load_length2(t_printf *spec, char **s)
{
	if (ft_strchr("qLjzZt", **s))
	{
		spec->length[0] = **s;
		spec->length[1] = 0;
		++(*s);
		if (**s != 0)
			return (1);
		return (0);
	}
	return (1);
}

int	load_length(t_printf *spec, char **s)
{
	if (**s == 'h')
	{
		++(*s);
		if (**s == 'h')
		{
			++(*s);
			ft_strcpy(spec->length, "hh");
		}
		else
			ft_strcpy(spec->length, "h");
		return (**s != 0);
	}
	if (**s == 'l')
	{
		++(*s);
		if (**s == 'l')
		{
			++(*s);
			ft_strcpy(spec->length, "ll");
		}
		else
			ft_strcpy(spec->length, "l");
		return (**s != 0);
	}
	return (load_length2(spec, s));
}

int	load_conversion(t_printf *spec, char **s)
{
	if (ft_strchr("diouxXeEfFgGaAcsCSpnm%", **s))
		spec->conversion = **s;
	else
		return (0);
	if (ft_strchr("CS", **s))
		ft_strcpy(spec->length, "l");
	++(*s);
	return (1);
}
