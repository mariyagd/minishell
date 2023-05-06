/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:36:08 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/26 00:09:18 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// BROKEN for now, use ft_bsort instead

// quicksort
//!\  max size of elements

#define MAXSZ	1024

typedef struct s_params
{
	size_t		sz;
	t_compar	f;
}	t_params;

static void	_swap(void *a, void *b, size_t sz)
{
	char	buf[MAXSZ];

	if (a == b)
		return ;
	ft_memcpy(buf, a, sz);
	ft_memcpy(a, b, sz);
	ft_memcpy(b, buf, sz);
}

static size_t	_partition(void *a, size_t lo, size_t hi, t_params *parms)
{
	size_t	piv;
	size_t	n;
	size_t	i;

	piv = hi;
	n = lo - 1;
	i = lo;
	while (i < hi - 1)
	{
		if ((*parms->f)(a + (i * parms->sz), a + (piv * parms->sz)) <= 0)
		{
			++n;
			_swap(a + (i * parms->sz), a + (n * parms->sz), parms->sz);
		}
		++i;
	}
	++n;
	_swap(a + (n * parms->sz), a + (piv * parms->sz), parms->sz);
	return (n);
}

static void	_qsort(void *a, size_t lo, size_t hi, t_params *parms)
{
	size_t	piv;

	if (lo + 1 == hi)
	{
		if ((*parms->f)(a + (lo * parms->sz), a + (hi * parms->sz)) > 0)
			_swap(a + (lo * parms->sz), a + (hi * parms->sz), parms->sz);
		return ;
	}
	piv = _partition(a, lo, hi, parms);
	if (piv && lo < piv - 1)
		_qsort(a, lo, piv - 1, parms);
	if (piv + 1 < hi)
		_qsort(a, piv + 1, hi, parms);
}

void	ft_qsort(void *a, size_t n, size_t sz, t_compar f)
{
	t_params	parms;

	if (n < 2)
		return ;
	parms.sz = sz;
	parms.f = f;
	_qsort(a, 0, n - 1, &parms);
}
