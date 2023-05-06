/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:42:31 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/16 21:18:31 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "ft_getnext.h"
#include "ft_getnextline.h"

static char	*_reader_erase_line(t_reader *m)
{
	char	*p;
	size_t	len;
	char	*s;

	p = ft_memchr(m->str, SEPARATOR_CHAR, m->slen);
	len = p - m->str + 1;
	if (m->slen == len)
	{
		ft_free(m->str);
		m->str = 0;
		m->slen = 0;
	}
	else
	{
		s = ft_malloc(sizeof(char) * (m->slen - len));
		if (!s)
			return (_reader_reset(m));
		ft_memcpy(s, p + 1, m->slen - len);
		ft_free(m->str);
		m->str = s;
		m->slen -= len;
	}
	return ((char *) 1);
}

static char	*_reader_last_line(t_reader *m)
{
	char	*s;

	if (!m->slen)
		return (_reader_reset(m));
	s = ft_malloc(sizeof(char) * (m->slen + 1));
	if (!s)
		return (_reader_reset(m));
	ft_memcpy(s, m->str, m->slen);
	s[m->slen] = 0;
	_reader_reset(m);
	return (s);
}

static char	*_reader_next_line(t_reader *m)
{
	char	*p;
	char	*s;

	if (m->slen)
	{
		p = ft_memchr(m->str, SEPARATOR_CHAR, m->slen);
		if (p)
		{
			s = ft_malloc(sizeof(char) * (p - m->str + 2));
			if (!s)
				return (_reader_reset(m));
			ft_memcpy(s, m->str, p - m->str + 1);
			s[p - m->str + 1] = 0;
			if (!_reader_erase_line(m))
			{
				ft_free(s);
				return (_reader_reset(m));
			}
			return (s);
		}
	}
	return (0);
}

static ssize_t	_reader_read_more(t_reader *m)
{
	ssize_t	ssz;
	char	buf[BUFFER_SIZE];
	char	*s;

	ssz = read(m->fd, buf, BUFFER_SIZE);
	if (ssz < 0)
	{
		_reader_reset(m);
		return (ssz);
	}
	if (ssz)
	{
		s = ft_malloc(sizeof(char) * (ssz + m->slen));
		if (!s)
			return ((ssize_t)_reader_reset(m));
		ft_memcpy(s, m->str, m->slen);
		ft_memcpy(s + m->slen, buf, ssz);
		if (m->str)
			ft_free(m->str);
		m->str = s;
		m->slen += ssz;
	}
	return (ssz);
}

char	*ft_getnextline(int fd)
{
	static __thread t_reader	*readers;
	t_reader					*m;
	char						*line;
	ssize_t						ssz;

	if (fd < 0)
		return (_reader_free(&readers));
	m = _reader_get(&readers, fd);
	if (!m)
		return (0);
	ssz = 1;
	while (ssz)
	{
		ssz = _reader_read_more(m);
		if (ssz < 0)
			return (0);
		line = _reader_next_line(m);
		if (line)
			return (line);
		if (ssz < BUFFER_SIZE)
			return (_reader_last_line(m));
	}
	return (0);
}
