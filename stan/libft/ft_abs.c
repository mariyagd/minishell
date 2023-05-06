/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:18:02 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/20 16:33:01 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int num)
{
	if (num >= 0)
		return (num);
	return (-(num));
}

long	ft_labs(long num)
{
	if (num >= 0)
		return (num);
	return (-(num));
}
