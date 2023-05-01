/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complicated_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:47:31 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/27 16:02:39 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_n_words(char *str, char c, int count)
{
	while (*str)
	{
		if (*str != c)
		{
			if (*str == '\'' && str++)
			{
				count++;
				while (*str && *str != '\'')
					str++;
				str++;
			}
			else
			{
				count++;
				while (*str && *str != c)
					str++;
			}
		}
		else
			str++;
	}
	return (count);
}

static int	*ft_len_strs(char *str, char c, int count, int index)
{
	int	*len_strs;
	int	len;

	len_strs = malloc(sizeof(int) * count);
	if (len_strs == 0)
		return (0);
	while (*str)
	{
		len = 0;
		if (*str == '\'' && str++)
			while (*str != '\'' && ++len)
				str++;
		else
			while (*str && *str != c && ++len)
				str++;
		if (*str == '\'')
			str++;
		if (*str == c)
			str++;
		len_strs[index++] = len + 1;
	}
	return (len_strs);
}

static char	**ft_free_split(char **dst, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
		free(dst[k++]);
	free(dst);
	return (NULL);
}

static char	**ft_fill_big_table(char *src, char c, char **dst, int *lens)
{
	int	j;
	int	count;

	count = 0;
	while (*src)
	{
		dst[count] = malloc(sizeof(char) * lens[count]);
		if (dst[count] == NULL)
			return (ft_free_split(dst, count));
		j = 0;
		if (*src == '\'' && src++)
			while (*src != '\'')
				dst[count][j++] = *src++;
		else
			while (*src && *src != c)
				dst[count][j++] = *src++;
		dst[count++][j] = '\0';
		if (*src == '\'')
			src++;
		if (*src == c)
			src++;
	}
	dst[count] = NULL;
	free(lens);
	return (dst);
}

char	**ft_splitpath(char *s, char c)
{
	char	**dst;
	int		*lens;
	int		count;
	int		index;

	index = 0;
	count = ft_n_words(s, c, 0);
	lens = ft_len_strs(s, c, count, index);
	dst = malloc(sizeof(char *) * (count + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_fill_big_table(s, c, dst, lens));
}
