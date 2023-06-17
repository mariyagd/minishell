/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:40:30 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/09 10:40:35 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] && ft_strchr(accept, s[i]) != 0)
	{
		count++;
		i++;
	}
	return (count);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int ac, char *av[])
{
	if (ac != 3)
		printf("\n");
	else
	{
		printf("%zu\n", strspn(av[1], av[2]));
		printf("%zu\n", ft_strspn(av[1], av[2]));
	}
	return (0);
}*/
