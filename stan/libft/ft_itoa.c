/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:53:19 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/28 19:42:13 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_itoa(char **p, int *n)
{
	while (*n)
	{
		**p = '0' + (*n % 10);
		*n /= 10;
		if (*n)
			--(*p);
	}
}

char	*ft_itoa(int n, char ret[12])
{
	char	buf[12];
	char	*p;
	int		neg;

	if (!n)
		return (ft_strcpy(ret, "0"));
	buf[11] = 0;
	p = &buf[10];
	if (n == INT_MIN)
	{
		*p-- = '8';
		n = -214748364;
	}
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -(n);
	}
	_ft_itoa(&p, &n);
	if (neg)
		*--p = '-';
	return (ft_strcpy(ret, p));
}

static void	_ft_lltoa(char **p, long long *n)
{
	while (*n)
	{
		**p = '0' + (*n % 10);
		*n /= 10;
		if (*n)
			--(*p);
	}
}

char	*ft_lltoa(long long n, char ret[21])
{
	char	buf[21];
	char	*p;
	int		neg;

	if (!n)
		return (ft_strcpy(ret, "0"));
	buf[20] = 0;
	p = &buf[19];
	if (n == LLONG_MIN)
	{
		*p-- = '8';
		n = -922337203685477580;
	}
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -(n);
	}
	_ft_lltoa(&p, &n);
	if (neg)
		*--p = '-';
	return (ft_strcpy(ret, p));
}
