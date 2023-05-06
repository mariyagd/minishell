/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 06:50:19 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/17 15:53:15 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

static void	*_realloc(t_arr *a, size_t nelem)
{
	void	*tmp;

	tmp = ft_calloc(nelem + 1, a->unit);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, a->data, a->nelem * a->unit);
	ft_free(a->data);
	return (tmp);
}

int	ft_arr_reserve(t_arr *a, size_t nelem)
{
	assert(a->unit);
	if (nelem < a->nelem)
		return (0);
	if (nelem > a->ncapacity - 1)
	{
		if (a->data)
			a->data = _realloc(a, nelem);
		else
			a->data = ft_calloc(nelem + 1, a->unit);
		if (!a->data)
			return (0);
		a->ncapacity = nelem + 1;
	}
	assert(a->ncapacity > a->nelem);
	return (1);
}
