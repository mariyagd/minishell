/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:10:43 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/15 20:12:21 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			size;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (len > size)
	len = size;
	if (start >= (unsigned int)size)
	{
		substr = (char *)malloc(1 * sizeof(char));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (i < (unsigned int)len && s[start] != '\0' )
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
