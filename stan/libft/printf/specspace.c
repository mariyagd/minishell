/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:12:38 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 01:28:40 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	spec_space(t_printf *spec, char **p)
{
	if (!arg_is_negative(spec))
	{
		if (!ft_prepend(p, " "))
			return (0);
	}
	return (1);
}
