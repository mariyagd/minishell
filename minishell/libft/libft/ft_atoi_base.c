/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:34:46 by mdanchev          #+#    #+#             */
/*   Updated: 2023/01/27 11:46:16 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include "../includes/get_next_line.h"

int	transform(char c)
{
	int		i;
	char	c2;

	i = 10;
	if (c >= 'A' && c <= 'F')
		c2 = 'A';
	if (c >= 'a' && c <= 'f')
		c2 = 'a';
	while (c != c2)
	{
		c2++;
		i++;
	}
	return (i);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	count;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	count = ft_strlen_int(str) - 1;
	sign = 1;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
		count--;
	}
	while (str[i++] != 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result + (str[i] - '0') * power(str_base, count);
		if ((str[i] >= 'A' && str[i] <= 'F') || \
				(str[i] >= 'a' && str[i] <= 'f'))
			result = result + transform(str[i]) * power(str_base, count);
		count--;
	}
	return (result * sign);
}

/*
#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
	}
	return (0);
}
*/
