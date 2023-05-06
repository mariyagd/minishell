/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:38:09 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/11 21:01:37 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef NMEMLIST

void	*ft_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (ft_multovf(nmemb, size))
		return (0);
	return (ft_realloc(ptr, nmemb * size));
}

#else

void	*ft_reallocarray(void *ptr, size_t nmemb, size_t size, size_t psz)
{
	if (ft_multovf(nmemb, size))
		return (0);
	return (ft_realloc(ptr, nmemb * size, psz));
}

#endif
