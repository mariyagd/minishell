/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:28:00 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:28:13 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_printf_str(char *s, int fd, int *count)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
			i++;
		ft_putstr_fd(s, fd);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		i = 6;
	}
	*count += i;
}
