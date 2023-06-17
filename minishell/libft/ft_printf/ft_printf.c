/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:37:00 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:28:41 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_format_specifier(char format, va_list ap, int *count)
{
	if (format == '%')
		ft_printf_char(format, 1, count);
	else if (format == 'c')
		ft_printf_char(va_arg(ap, int), 1, count);
	else if (format == 's')
		ft_printf_str(va_arg(ap, char *), 1, count);
	else if (format == 'd' || format == 'i')
		ft_printf_int(va_arg(ap, int), 1, count);
	else if (format == 'u')
		ft_printf_unsint(va_arg(ap, unsigned int), 1, count);
	else if (format == 'p')
		ft_printf_address(va_arg(ap, uintptr_t), 1, count);
	else if (format == 'x' || format == 'X')
		ft_printf_hexa(va_arg(ap, int), 1, count, format);
}

int	ft_printf(const char *last, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	va_start(ap, last);
	i = 0;
	count = 0;
	while (last[i] != '\0')
	{
		if (last[i] != '%')
			ft_printf_char(last[i], 1, &count);
		else if (last[i] == '%')
		{
			if (last[i + 1] == '%')
				ft_printf_char(last[i + 1], 1, &count);
			else
				ft_format_specifier(last[i + 1], ap, &count);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
