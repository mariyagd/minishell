/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:42:04 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/25 10:00:23 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	using "uname -a" if neofetch isnt found,
//	but we could go for some ascii art :)

void	splash(void)
{
	char	*p;

	p = abspath_find("neofetch");
	if (!p)
	{
		p = abspath_find("uname");
		if (!p)
			return ;
		ft_free(p);
		if (!ft_strdup2("uname -a", &p))
			enomem();
		ft_putstr("\e[1m", STDOUT_FILENO);
		interp(p);
		ft_putstr("\e[0m", STDOUT_FILENO);
	}
	else
	{
		ft_free(p);
		if (!ft_strdup2("neofetch", &p))
			enomem();
		interp(p);
	}
}
