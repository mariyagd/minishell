/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:04:22 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/19 18:05:23 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// delete a list of pointers, passed by reference

void	ft_del_arr(void *p)
{
	char	***arr;
	size_t	i;

	arr = (char ***) p;
	if (*arr)
	{
		i = 0;
		while (1)
		{
			if ((*arr)[i])
				ft_free((*arr)[i++]);
			else
				break ;
		}
		ft_free(*arr);
		*arr = 0;
	}
}
