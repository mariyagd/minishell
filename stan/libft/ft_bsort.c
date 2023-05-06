/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:47:02 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/16 19:09:07 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// bubblesort
//!\  max size of elements

#define MAXSZ	1024

static void	_swap(void *a, void *b, size_t sz)
{
	char	buf[MAXSZ];

	ft_memcpy(buf, a, sz);
	ft_memcpy(a, b, sz);
	ft_memcpy(b, buf, sz);
}

void	ft_bsort(void *a, size_t n, size_t sz, t_compar f)
{
	size_t	i;
	size_t	j;
	void	*p;
	void	*q;

	if (n < 2 || !sz || sz > MAXSZ)
		return ;
	i = 0;
	j = 1;
	while (i < n - 1)
	{
		p = a + (i * sz);
		q = a + (j * sz);
		if ((*f)(p, q) > 0)
			_swap(p, q, sz);
		else
			++j;
		if (j == n)
		{
			++i;
			j = i + 1;
		}
	}
}
