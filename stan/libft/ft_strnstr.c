/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:44:32 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/15 02:00:28 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	nlen = ft_strlen(needle);

	if (!nlen)
		return ((char *) haystack);
	while (*haystack && len >= nlen)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, nlen))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (0);
}
