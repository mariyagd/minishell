/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:13:24 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:27:33 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_printf_hexa(unsigned int n, int fd, int *count, char c)
{
	if (n > 15)
	{
		ft_printf_hexa(n / 16, fd, count, c);
		ft_printf_hexa(n % 16, fd, count, c);
	}
	if (n < 10)
		ft_printf_char(n + 48, fd, count);
	else if (n > 9 && n < 16)
	{
		if (c == 'x')
			ft_printf_char(n + 87, fd, count);
		else if (c == 'X')
			ft_printf_char(n + 55, fd, count);
	}
}
