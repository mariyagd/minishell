/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:31:56 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/01 16:38:21 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int a, size_t x)
{
	int		b;
	size_t	i;

	if (!x)
		return (0);
	b = a;
	i = 1;
	while (i++ < x)
		b *= a;
	return (b);
}
