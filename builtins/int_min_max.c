/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:39:34 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/09 20:32:48 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static int	negative_int_check(char *str)
{
	char	*s_int_min;
	int		len;

	if (!str)
		return (0);
	s_int_min = "-9223372036854775808";
	len = ft_strlen(str);
	if (len > 20)
		return (0);
	if (len == 20 && ft_strncmp(s_int_min, str, 20) < 0)
		return (0);
	return (1);
}

static int	positive_int_check(char *str)
{
	char	*s_int_max;
	int		len;

	if (!str)
		return (0);
	s_int_max = "+9223372036854775807";
	len = ft_strlen(str);
	if (len > 20)
		return (0);
	if (len == 20 && ft_strncmp(s_int_max, str, 20) < 0)
		return (0);
	return (1);
}

static int	int_check(char *str)
{
	char	*s_int_max;
	int		len;

	s_int_max = "9223372036854775807";
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (len > 19)
		return (0);
	if (len == 19 && ft_strncmp(s_int_max, str, 19) < 0)
		return (0);
	return (1);
}

int	no_int_errors(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '-')
	{
		if (!negative_int_check(str))
			return (0);
	}
	else if (str[0] == '+')
	{
		if (!positive_int_check(str))
			return (0);
	}
	else
	{
		if (!int_check(str))
			return (0);
	}
	return (1);
}
