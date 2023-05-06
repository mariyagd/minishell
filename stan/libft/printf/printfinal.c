/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfinal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:08:24 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/12 01:56:11 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_p.h"

int	print_final_sz(char *s, size_t sz, int *cnt, int fd)
{
	if (!ft_putstr_sz(s, sz, fd))
	{
		ft_free(s);
		return (0);
	}
	*cnt += sz;
	ft_free(s);
	return (1);
}

int	print_final(char *s, int *cnt, int fd)
{
	const size_t	sz = ft_strlen(s);

	return (print_final_sz(s, sz, cnt, fd));
}

int	print_final_buf(char *s, int *cnt, int fd)
{
	const size_t	sz = ft_strlen(s);

	if (!ft_putstr_sz(s, sz, fd))
		return (0);
	*cnt += sz;
	return (1);
}
