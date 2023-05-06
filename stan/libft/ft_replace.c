/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:18:05 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/23 02:30:52 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_parms
{
	char	*this;
	size_t	sz1;
	char	*that;
	size_t	sz2;
}	t_parms;

static size_t	_count(const char *s, const char *this, size_t n)
{
	size_t	cnt;

	if (n == 0)
		return (0);
	cnt = 0;
	while (*s)
	{
		s = ft_strstr(s, this);
		if (s)
		{
			++cnt;
			s += n;
		}
		else
			break ;
	}
	return (cnt);
}

static void	_copy(char *p, const char *that)
{
	while (*that)
		*p++ = *that++;
}

static char	*_replace(char **s, t_parms *parms, char *new)
{
	char	*p;
	char	*p2;
	char	*n;

	p = *s;
	n = new;
	while (*p)
	{
		p2 = ft_strstr(p, parms->this);
		if (!p2)
		{
			ft_strcpy(n, p);
			break ;
		}
		ft_strncpy(n, p, p2 - p);
		n += p2 - p;
		_copy(n, parms->that);
		n += parms->sz2;
		p = p2 + parms->sz1;
	}
	ft_free(*s);
	*s = new;
	return (new);
}

//	replace all occurrences of 'this' found in 's' by 'that'

char	*ft_replace(char **s, const char *this, const char *that)
{
	t_parms		parms;
	const int	cnt = (int) _count(*s, this, ft_strlen2(this, &parms.sz1));
	int			delta;
	size_t		newlen;
	char		*newstr;

	if (cnt == 0 || parms.sz1 == 0)
		return (*s);
	delta = ((int) ft_strlen2(that, &parms.sz2)) - ((int) parms.sz1);
	newlen = ft_strlen(*s) + (cnt * delta);
	newstr = ft_calloc(1, newlen + 1);
	if (!newstr)
		return (0);
	parms.this = (char *) this;
	parms.that = (char *) that;
	return (_replace(s, &parms, newstr));
}
