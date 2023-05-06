/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:57:45 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/09 17:36:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

static inline void	specinit(t_printf *spec, int fd)
{
	ft_memset(spec, 0, sizeof(t_printf));
	spec->fd = fd;
}

static int	load_flags(t_printf *spec, char **s)
{
	if (**s == '#')
		return (flag_hash(spec, s));
	if (**s == '0')
		return (flag_zero(spec, s));
	if (**s == '-')
		return (flag_minus(spec, s));
	if (**s == ' ')
		return (flag_space(spec, s));
	if (**s == '+')
		return (flag_plus(spec, s));
	if (**s == '\'')
		return (flag_apostrophe(spec, s));
	if (**s == 'I')
		return (flag_upper_i(spec, s));
	return (0);
}

char	*load(int fd, t_printf *spec, char *s)
{
	if (!*s)
		return (0);
	specinit(spec, fd);
	while (ft_strchr("#0- +'I", *s))
	{
		if (!load_flags(spec, &s))
			return (0);
	}
	if (!load_field_width(spec, &s) || !load_precision(spec, &s)
		|| !load_length(spec, &s) || !load_conversion(spec, &s))
		return (0);
	return (s);
}
