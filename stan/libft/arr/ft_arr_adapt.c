/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_adapt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:21:39 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/12 19:49:39 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

int	ft_arr_adapt(t_arr *a)
{
	void	*tmp;

	if (a->ncapacity != a->nelem + 1)
	{
		tmp = ft_calloc(a->nelem + 1, a->unit);
		if (!tmp)
			return (0);
		ft_memcpy(tmp, a->data, a->nelem * a->unit);
		ft_free(a->data);
		a->data = tmp;
		a->ncapacity = a->nelem + 1;
	}
	return (1);
}
