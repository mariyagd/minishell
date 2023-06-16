/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:03:26 by mdanchev          #+#    #+#             */
/*   Updated: 2023/01/27 12:04:25 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	power(int str_base, int power)
{
	int	result;

	result = 1;
	if (power < 0 || str_base == 0)
	{
		return (0);
	}
	while (power > 0)
	{
		result = result * str_base;
		power--;
	}
	return (result);
}
