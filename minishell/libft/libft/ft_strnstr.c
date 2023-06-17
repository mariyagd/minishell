/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:15:52 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/20 14:08:35 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	len_haystack;

	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	if (needle[0] == '\0')
		return ((char *)(haystack));
	if (len_needle > len_haystack || len < len_needle)
		return (NULL);
	if (len > len_haystack)
		len = len_haystack;
	while (len >= len_needle && haystack)
	{
		if (ft_memcmp(haystack, needle, len_needle) == 0)
			return ((char *)(haystack));
		else
		{
			haystack++;
			len--;
		}
	}
	return (NULL);
}
