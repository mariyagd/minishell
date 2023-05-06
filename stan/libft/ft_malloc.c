/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:38:13 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/27 00:02:24 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef PREALLOC

void	*ft_malloc(size_t sz)
{
	ptrdiff_t	*nextptr;
	void		*ptr;

	if (!sz)
		return (0);
	nextptr = ft_bufptr();
	ptr = ft_buffer(0) + *nextptr;
	*nextptr += sz;
	return (ptr);
}

#elif !defined( NMEMLIST )

void	*ft_malloc(size_t sz)
{
	t_memlist	*p;

	if (!sz)
		return (0);
	p = malloc(sizeof(t_memlist) + sz);
	if (!p)
		return (0);
	p->sz = sz;
	ft_sllist_push(ft_memlist(), p);
	return (p->data);
}

#else

void	*ft_malloc(size_t sz)
{
	return (malloc(sz));
}

#endif
