/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:15:45 by pmarquis          #+#    #+#             */
/*   Updated: 2023/01/05 20:09:30 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_atoui(const char *s, unsigned int *ret)
{
	unsigned int	i;

	while (*s && ft_isspace(*s))
		++s;
	if (*s == '-')
		return (0);
	if (*s == '+')
		++s;
	if (!ft_isdigit(*s))
		return (0);
	i = 0;
	while (*s && ft_isdigit(*s))
	{
		i *= 10;
		i += *s - '0';
		++s;
	}
	*ret = i;
	return ((char *) s);
}

char	*ft_atoul(const char *s, unsigned long *ret)
{
	unsigned long	i;

	while (*s && ft_isspace(*s))
		++s;
	if (*s == '-')
		return (0);
	if (*s == '+')
		++s;
	if (!ft_isdigit(*s))
		return (0);
	i = 0;
	while (*s && ft_isdigit(*s))
	{
		i *= 10;
		i += *s - '0';
		++s;
	}
	*ret = i;
	return ((char *) s);
}

char	*ft_atoull(const char *s, t_ullong *ret)
{
	t_ullong	i;

	while (*s && ft_isspace(*s))
		++s;
	if (*s == '-')
		return (0);
	if (*s == '+')
		++s;
	if (!ft_isdigit(*s))
		return (0);
	i = 0;
	while (*s && ft_isdigit(*s))
	{
		i *= 10;
		i += *s - '0';
		++s;
	}
	*ret = i;
	return ((char *) s);
}

char	*ft_atosz(const char *s, size_t *ret)
{
	size_t	i;

	while (*s && ft_isspace(*s))
		++s;
	if (*s == '-')
		return (0);
	if (*s == '+')
		++s;
	if (!ft_isdigit(*s))
		return (0);
	i = 0;
	while (*s && ft_isdigit(*s))
	{
		i *= 10;
		i += *s - '0';
		++s;
	}
	*ret = i;
	return ((char *) s);
}
