/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:25:13 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/20 11:27:07 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	strlen_src;
	size_t	strlen_dst;
	size_t	temp;

	i = 0;
	strlen_src = ft_strlen(src);
	strlen_dst = ft_strlen(dst);
	temp = strlen_dst;
	if (dstsize < strlen_dst)
		return (dstsize + strlen_src);
	if (dstsize > strlen_dst + 1)
	{
		while (src[i] && strlen_dst != (dstsize - 1))
		{
			dst[strlen_dst++] = src[i++];
		}
		dst[strlen_dst] = '\0';
	}
	return (temp + strlen_src);
}
