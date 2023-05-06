/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnext.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:27:44 by pmarquis          #+#    #+#             */
/*   Updated: 2022/12/17 00:47:26 by pmarquis         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETNEXT_H
# define FT_GETNEXT_H

# include <libft.h>

char		*ft_getnextline(int fd);
char		**ft_getfile(int fd);

#endif
