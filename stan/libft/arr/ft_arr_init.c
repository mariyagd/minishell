/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:49:07 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/14 17:12:58 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

int	ft_arr_init(t_arr *a, size_t nelem, size_t unit)
{
	assert(unit);
	a->nelem = 0;
	a->unit = unit;
	a->ncapacity = 0;
	a->data = ft_calloc(nelem + 1, unit);
	if (!a->data)
		return (0);
	a->ncapacity = nelem + 1;
	return (1);
}
