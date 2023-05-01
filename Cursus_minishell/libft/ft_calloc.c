/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:22:40 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/09 09:20:00 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	n_bytes;

	n_bytes = count * size;
	ptr = malloc(n_bytes);
	if (ptr == 0)
		return (0);
	ptr = ft_memset(ptr, 0, n_bytes);
	return (ptr);
}
