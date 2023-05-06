/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:45:02 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/19 18:16:31 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returned string must be freed

char	*ft_strnew(char **ps, const char *s)
{
	char	*p;

	*ps = ft_malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!*ps)
		return (0);
	p = *ps;
	while (*s)
		*p++ = *s++;
	*p = 0;
	return (*ps);
}
