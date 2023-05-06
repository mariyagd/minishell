/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:02:48 by pmarquis          #+#    #+#             */
/*   Updated: 2022/11/14 18:02:50 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	char	*ret;

	if (!s)
		return (0);
	p = ft_malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (0);
	ret = p;
	while (*s)
		*p++ = *s++;
	*p = 0;
	return (ret);
}
