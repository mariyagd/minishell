/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:44:53 by mdanchev          #+#    #+#             */
/*   Updated: 2023/05/08 11:10:21 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/* DOLLAR IS A SPECIAL CHARECTER AND DELIMITER*/

int	is_dollar(char c)
{
	if (c == '$')
		return (1);
	return (0);
}
