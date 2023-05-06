/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:08:55 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/25 22:38:58 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

long	ft_lmax(long a, long b)
{
	if (a >= b)
		return (a);
	return (b);
}

t_ulong	ft_ulmax(t_ulong a, t_ulong b)
{
	if (a >= b)
		return (a);
	return (b);
}
