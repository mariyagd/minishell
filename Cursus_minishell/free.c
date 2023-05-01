/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <ymarival@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:21:55 by ymarival          #+#    #+#             */
/*   Updated: 2023/04/28 12:27:19 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*free_tab(void **a_free)
{
	if (*a_free)
		free(*a_free);
	*a_free = NULL;
	return (NULL);
}

