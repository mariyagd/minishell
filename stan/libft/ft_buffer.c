/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:19:30 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/25 00:45:05 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_buffer(void *newbuf)
{
	static __thread void	*buf;

	if (newbuf)
	{
		buf = newbuf;
		*ft_bufptr() = 0;
	}
	return (buf);
}
