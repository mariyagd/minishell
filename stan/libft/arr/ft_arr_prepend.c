/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_prepend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:50:52 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/14 04:50:20 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

void	*ft_arr_prepend(t_arr *a, void *p, t_fn2 copyfunc)
{
	return (ft_arr_insert(a, p, 0, copyfunc));
}
