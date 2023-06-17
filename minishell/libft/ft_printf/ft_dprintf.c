/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:37:00 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:28:41 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_format_specifier_fd(char format, va_list ap, int *count, int fd)
{
	if (format == '%')
		ft_printf_char(format, fd, count);
	else if (format == 'c')
		ft_printf_char(va_arg(ap, int), fd, count);
	else if (format == 's')
		ft_printf_str(va_arg(ap, char *), fd, count);
	else if (format == 'd' || format == 'i')
		ft_printf_int(va_arg(ap, int), fd, count);
	else if (format == 'u')
		ft_printf_unsint(va_arg(ap, unsigned int), fd, count);
	else if (format == 'p')
		ft_printf_address(va_arg(ap, uintptr_t), fd, count);
	else if (format == 'x' || format == 'X')
		ft_printf_hexa(va_arg(ap, int), fd, count, format);
}

int	ft_dprintf(int fd, const char *last, ...)
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
			ft_printf_char(last[i], fd, &count);
		else if (last[i] == '%')
		{
			if (last[i + 1] == '%')
				ft_printf_char(last[i + 1], fd, &count);
			else
				ft_format_specifier_fd(last[i + 1], ap, &count, fd);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
