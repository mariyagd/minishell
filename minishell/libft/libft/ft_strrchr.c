/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:35:05 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/20 12:38:07 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			k = i;
		i++;
	}
	if (s[k] == (char)c)
		return ((char *)(s + k));
	else if ((char)c == s[i])
		return ((char *)(s + i));
	else
		return (NULL);
}
