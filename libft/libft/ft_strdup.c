/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:27:10 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/20 15:03:25 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s1_copie;

	size = ft_strlen(s1) + 1;
	s1_copie = (char *)malloc(size * sizeof(char));
	if (!s1_copie)
		return (NULL);
	ft_strlcpy(s1_copie, s1, size);
	return (s1_copie);
}
