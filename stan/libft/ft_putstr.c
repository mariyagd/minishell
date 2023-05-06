/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:25:34 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/19 18:25:18 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(const char *s, int fd)
{
	const size_t	sz = ft_strlen(s);

	if (sz && write(fd, s, sz) != (ssize_t) sz)
		return (0);
	return (1);
}
