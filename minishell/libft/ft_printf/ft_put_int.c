/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:22:21 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:29:26 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_put_int(int n, int fd, int *count)
{
	int	a;

	a = *count;
	ft_putnbr_fd(n, fd);
	a += ft_count_int(n);
	return (a);
}
