/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:10:22 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/23 18:52:24 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	count number of elements in an array of pointers

size_t	ft_count_arr(void *a)
{
	char	**arr;
	size_t	i;

	arr = a;
	i = 0;
	while (arr[i])
		++i;
	return (i);
}
