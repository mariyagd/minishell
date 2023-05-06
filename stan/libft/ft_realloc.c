/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:38:23 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/23 18:54:10 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef NMEMLIST

static inline void	*_undefined_behavior(void)
{
	char	*p;

	assert(0);
	p = 0;
	*p = 0;
	return (0);
}

static inline int	_ft_realloc2(t_memlist **q, t_memlist *p, size_t sz)
{
	*q = malloc(sizeof(t_memlist) + sz);
	if (!*q)
		return (0);
	(*q)->next = 0;
	(*q)->sz = sz;
	if (sz >= p->sz)
		ft_memcpy((*q)->data, p->data, p->sz);
	else
		ft_memcpy((*q)->data, p->data, sz);
	return (1);
}

static inline void	*_ft_realloc(void *ptr, size_t sz)
{
	t_memlist	**lst;
	t_memlist	*p;
	t_memlist	*prev;
	t_memlist	*q;

	lst = ft_memlist();
	p = *lst;
	prev = 0;
	while (p)
	{
		if (p->data == ptr)
		{
			if (p->sz == sz)
				return (p);
			ft_sllist_take(lst, p, prev);
			if (!_ft_realloc2(&q, p, sz))
				return (0);
			ft_sllist_push(lst, q);
			free(p);
			return (q->data);
		}
		prev = p;
		p = p->next;
	}
	return (_undefined_behavior());
}

void	*ft_realloc(void *ptr, size_t sz)
{
	if (!ptr)
	{
		if (sz)
			return (ft_malloc(sz));
		return (0);
	}
	if (!sz)
	{
		ft_free(ptr);
		return (0);
	}
	return (_ft_realloc(ptr, sz));
}

#else // def NMEMLIST

void	*ft_realloc(void *ptr, size_t sz, size_t psz)
{
	char	*q;

	if (!ptr)
	{
		if (sz)
			return (malloc(sz));
		return (0);
	}
	if (!sz)
	{
		free(ptr);
		return (0);
	}
	q = malloc(sz);
	if (!q)
		return (0);
	if (sz >= psz)
		ft_memcpy(q, ptr, psz);
	else
		ft_memcpy(q, ptr, sz);
	free(ptr);
	return (q);
}

#endif // ndef NMEMLIST
