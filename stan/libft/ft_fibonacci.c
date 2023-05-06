/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:44:57 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/26 00:57:11 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ullong	ft_fibonacci(size_t n)
{
	if (n < 2)
		return (1ULL);
	return (ft_fibonacci(n - 2) + ft_fibonacci(n - 1));
}
