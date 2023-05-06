/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_fini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:36:03 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/17 03:36:57 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	var_fini(t_var *var)
{
	if (var->name)
		ft_del(&var->name);
	if (var->value)
		ft_del(&var->value);
	return (0);
}
