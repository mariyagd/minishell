/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:23:39 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/04 16:18:19 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_mod(int n, int fd)
{
	int	mod;

	if (n != 0)
	{
		ft_mod(n / 10, fd);
		mod = n % 10 + '0';
		write(fd, &mod, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 0)
		ft_mod(n, fd);
	else if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n = n * (-1);
		write(fd, "-", 1);
		ft_mod(n, fd);
	}
}
