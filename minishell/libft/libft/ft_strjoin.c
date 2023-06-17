/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:53:50 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/20 14:32:42 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*strjoin;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	strjoin = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	ft_memcpy(strjoin, s1, size_s1);
	ft_memcpy((strjoin + size_s1), s2, size_s2);
	ft_memset((strjoin + size_s1 + size_s2), 0, 1);
	return (strjoin);
}	
