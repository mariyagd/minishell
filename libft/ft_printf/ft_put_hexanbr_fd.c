/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexanbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:01:55 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:29:00 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_put_hexanbr_fd(unsigned int n, int fd, int *count)
{
	if (n > 15)
	{
		ft_put_hexanbr_fd(n / 16, fd, count);
		ft_put_hexanbr_fd(n % 16, fd, count);
	}
	if (n < 10)
		ft_printf_char(n + 48, fd, count);
	else if (n > 9 && n < 16)
		ft_printf_char(n + 87, fd, count);
}
