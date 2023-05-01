/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:48:42 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/10 19:31:01 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	char	*src;
	int		len;
	int		i;
	int		k;

	len = ft_strlen(s1);
	src = (char *)s1;
	i = 0;
	while (ft_check(src[i], set))
		i++;
	while ((len - 1) > 0 && ft_check(src[len - 1], set))
		len--;
	if ((len - i) < 0)
		len = i;
	dst = malloc(sizeof(char) * (len - i + 1));
	if (dst == 0)
		return (NULL);
	k = 0;
	while (i < len)
		dst[k++] = src[i++];
	dst[k] = '\0';
	return (dst);
}
