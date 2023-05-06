/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_sz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:09:50 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/19 18:10:10 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_sz(const char *s, size_t sz, int fd)
{
	if (sz && write(fd, s, sz) != (ssize_t) sz)
		return (0);
	return (1);
}
