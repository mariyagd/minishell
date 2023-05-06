/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:48:10 by pmarquis          #+#    #+#             */
/*   Updated: 2023/02/24 23:58:07 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_comp(char **s1, char **s2)
{
	return (ft_strcmp(*s1, *s2));
}

static void	_loop(DIR *dir, t_arr *lst)
{
	struct dirent	*st_dir;
	char			*p;

	while (1)
	{
		errno = 0;
		st_dir = readdir(dir);
		if (!st_dir)
		{
			if (errno)
			{
				error("readdir", strerror(errno));
				ft_arr_del(&lst, &ft_del);
			}
			return ;
		}
		if (*st_dir->d_name == '.')
			continue ;
		p = ft_strdup(st_dir->d_name);
		if (!p || !ft_arr_append(lst, &p, 0))
			enomem();
	}
}

static t_arr	*_wildcard(void)
{
	DIR		*dir;
	t_arr	*lst;

	dir = opendir(".");
	if (!dir)
	{
		error("opendir", strerror(errno));
		return (0);
	}
	if (!ft_arr_new(&lst, 1, sizeof(char *)))
		enomem();
	_loop(dir, lst);
	if (closedir(dir) == -1)
		error("closedir", strerror(errno));
	ft_bsort(lst->data, lst->nelem, lst->unit, (t_compar) & _comp);
	return (lst);
}

//	substitute the '*' at index 'idx' with the list of files
//	will return 0 if something goes wrong (read error etc)

int	wildcard(t_arr *args, size_t idx)
{
	t_arr	*lst;
	size_t	i;
	char	**s;

	lst = _wildcard();
	if (!lst)
		return (0);
	if (!ft_arr_unset(args, idx, &ft_del))
		enomem();
	i = -1;
	while (++i < lst->nelem)
	{
		s = ft_arr_get(lst, i);
		if (!ft_arr_insert(args, s, idx++, 0))
			enomem();
		*s = 0;
	}
	ft_arr_del(&lst, &ft_del);
	return (1);
}
