/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:20:17 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:26:45 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_count_unsigned_int(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	else if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			count++;
		}
	}
	return (count);
}
