/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:00:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/02 19:05:59 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*_ft_dtoa(double d, size_t precision, char ret[])
{
	char		buf[32];
	size_t		sz;
	long double	ld;
	char		*p;

	sz = 0;
	ld = d;
	p = buf;
	while (sz++ < precision)
	{
		ld *= 10.000000000000001;
		if (ld < 1)
			*p++ = '0';
	}
	ft_itoa((int) ld, p);
	if (ft_strlen2(buf, &sz) < precision)
		ft_strcatchr(buf, '0', precision - sz);
	return (ft_strcat(ret, buf));
}

char	*ft_dtoa(double d, size_t precision, char ret[])
{
	if (d < 0 && d > -1)
		*ret++ = '-';
	if (!ft_itoa((int) d, ret))
		return (0);
	if (!precision)
		return (ret);
	ft_strcatchr(ret, '.', 1);
	if (d < 0)
		d = -(d);
	d -= (int) d;
	return (_ft_dtoa(d, precision, ret));
}

static void	_ft_dtoa_e(double *d, int *i)
{
	if (*d && *d < 1 && *d > -1)
	{
		*d *= 10;
		*i = -1;
		return ;
	}
	if (*d >= 0)
	{
		while (*d > 10)
		{
			*d /= 10;
			++*i;
		}
	}
	else
	{
		while (*d < -10)
		{
			*d /= 10;
			++*i;
		}
	}
}

char	*ft_dtoa_e(double d, size_t precision, char ret[])
{
	int		i;
	char	buf[12];

	i = 0;
	_ft_dtoa_e(&d, &i);
	ft_dtoa(d, precision, ret);
	if (i >= 0)
		ft_strcat(ret, "e+");
	else
	{
		ft_strcat(ret, "e-");
		i = -(i);
	}
	ft_itoa(i, buf);
	if (!buf[1])
		ft_strcatchr(ret, '0', 1);
	return (ft_strcat(ret, buf));
}

char	*ft_dtoa_ee(double d, size_t precision, char ret[])
{
	int		i;
	char	buf[12];

	i = 0;
	_ft_dtoa_e(&d, &i);
	ft_dtoa(d, precision, ret);
	if (i >= 0)
		ft_strcat(ret, "E+");
	else
	{
		ft_strcat(ret, "E-");
		i = -(i);
	}
	ft_itoa(i, buf);
	if (!buf[1])
		ft_strcatchr(ret, '0', 1);
	return (ft_strcat(ret, buf));
}
