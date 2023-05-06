/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:41:22 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/16 21:17:12 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETNEXTLINE_H
# define FT_GETNEXTLINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# ifndef SEPARATOR_CHAR
#  define SEPARATOR_CHAR	'\n'
# endif

typedef struct s_reader
{
	int				fd;
	char			*str;
	size_t			slen;
	struct s_reader	*next;
	struct s_reader	**first;
}	t_reader;

static char	*_reader_free(t_reader **readers)
{
	t_reader	*m;
	t_reader	*next;

	m = *readers;
	while (m)
	{
		next = m->next;
		if (m->str)
			ft_free(m->str);
		ft_free(m);
		m = next;
	}
	*readers = 0;
	return (0);
}

static t_reader	*_reader_get(t_reader **readers, int fd)
{
	t_reader	*m;
	t_reader	*prev;

	m = *readers;
	prev = 0;
	while (m)
	{
		if (m->fd == fd)
			return (m);
		prev = m;
		m = m->next;
	}
	m = ft_malloc(sizeof(t_reader));
	if (!m)
		return (0);
	m->fd = fd;
	m->str = 0;
	m->slen = 0;
	m->next = 0;
	m->first = readers;
	if (prev)
		prev->next = m;
	else
		*readers = m;
	return (m);
}

static char	*_reader_reset(t_reader *m)
{
	t_reader	*r;
	t_reader	*prev;

	r = *(m->first);
	prev = 0;
	while (r)
	{
		if (r == m)
		{
			if (prev)
				prev->next = m->next;
			else
				*(m->first) = m->next;
			if (m->str)
				ft_free(m->str);
			ft_free(m);
			return (0);
		}
		prev = r;
		r = r->next;
	}
	return (0);
}

#endif
