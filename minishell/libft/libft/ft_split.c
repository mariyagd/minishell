/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:13:17 by mdanchev          #+#    #+#             */
/*   Updated: 2022/10/17 12:55:47 by mdanchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

size_t	ft_count_nbsubstr(const char *s, char c)
{
	unsigned int	i;
	size_t			count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
		while (s[i] == c)
			i++;
	}
	return (count);
}

unsigned int	ft_start_index_substr(char const *s, char c, unsigned int start)
{
	while (s[start] == c && s[start] != '\0')
		start++;
	return (start);
}

unsigned int	ft_nb_char_substr(char const *s, char c, unsigned int start)
{
	unsigned int	nb_char_substr;

	nb_char_substr = 0;
	while (s[start] != c && s[start] != '\0')
	{
		start++;
		nb_char_substr++;
	}
	return (nb_char_substr);
}

char	*ft_create_substr(\
		char const *s, char c, unsigned int start, unsigned int nb_char_substr)
{
	unsigned int	i;
	char			*substr;

	i = 0;
	substr = (char *)ft_calloc((nb_char_substr + 1), sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start] != c && s[start] != '\0' && i < nb_char_substr)
		substr[i++] = s[start++];
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	size_t			nb_substr;
	size_t			i;
	char			**tab2d;
	unsigned int	start;
	unsigned int	nb_char_substr;

	i = 0;
	start = 0;
	nb_substr = ft_count_nbsubstr(s, c);
	tab2d = (char **)ft_calloc((nb_substr + 1), sizeof(char *));
	if (!tab2d)
		return (NULL);
	while (s[start] != '\0' && i < nb_substr)
	{
		start = ft_start_index_substr(s, c, start);
		nb_char_substr = ft_nb_char_substr(s, c, start);
		tab2d[i] = ft_create_substr(s, c, start, nb_char_substr);
		start = start + nb_char_substr;
		i++;
	}
	return (tab2d);
}
