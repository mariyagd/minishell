/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multovf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:17:49 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/08 02:18:09 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_multovf(size_t a, size_t b)
{
	size_t	x;

	x = a * b;
	if (a != 0 && x / a != b)
		return (1);
	return (0);
}
