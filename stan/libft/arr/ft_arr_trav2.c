/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_trav2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:16:58 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 04:41:13 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

void	ft_arr_trav2(t_arr *a, t_fn2 f, void *userdata)
{
	size_t	i;

	i = -1;
	while (++i < a->nelem)
		(*f)(a->data + (i * a->unit), userdata);
}
