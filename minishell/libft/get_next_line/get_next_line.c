/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:39:35 by mdanchev          #+#    #+#             */
/*   Updated: 2022/12/21 13:30:27 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/get_next_line.h"

char	*create_nextline(char *result, char *line)
{
	int		start;
	int		size;
	char	*nextline;

	start = ft_strlen_int(result);
	size = ft_strlen_int(line);
	size = size - start;
	if (size == 0)
	{
		free (line);
		return (NULL);
	}
	nextline = malloc((size + 1) * sizeof(char));
	if (!nextline)
		return (NULL);
	size = 0;
	while (line[start] != '\0')
	{
		nextline[size] = line[start];
		size++;
		start++;
	}
	nextline[size] = '\0';
	free(line);
	return (nextline);
}

/*
	si there_is_n renvoie -1 cela veut dire que
		- soit line n'est pas vide mais line ne contient pas de '\n'
		- soit line est vide donc line[0] == '\0'
	if (i == -1 && *line)
		<=> si line ne contient pas de '\n' et line n'est pas vide, la
		taille de result = ft_strlen(line)
	if (i == -1 && !*line)
		<=> si line ne contient pas de '\n' et line est vide, return (NULL)
	*line <=> line[0] <=> line[0] != 0 <=> line[0] != '\0'
*/

char	*create_result(char *line)
{
	int		i;
	char	*result;

	i = there_is_n(line);
	if (i == -1 && *line)
		i = ft_strlen_int(line);
	else if (i == -1 && !*line)
		return (NULL);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		result[i] = line[i];
		if (line[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
	- si line n'existe pas, line est initialisée à
	 line[0] = '\0' avec ft_calloc

	- je vérifie la présence d'un '\n' dans le buffer,
	 parce que c'est la plus courte chaîne

	-si buffer ne contient pas de '\n' la fonction
	there_is_n renvoie un chiffre différent de -1
*/

char	*read_fd(char *line, int fd, int *error)
{
	char	*buffer;
	int		ret;

	ret = 1;
	prepare_forstash(&line, &buffer);
	while (ret > 0 && there_is_n(buffer) == -1 && there_is_n(line) == -1)
	{
		ret = (int)read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buffer);
			*error = -1;
			return (NULL);
		}
		if (ret == 0)
		{
			*error = 0;
			break ;
		}
		buffer[ret] = '\0';
		line = ft_join(line, buffer);
	}
	free(buffer);
	return (line);
}

/*
	read(fd, 0, 0) == read(fd, NULL, 0) est un test
	qui fait toutes les verifications d'erreurs usuel
	sur le file descriptor, sans retirer des donees.
	Il permet de determine si le file descriptor est valid.
	Le test retourn -1 s'il y a des erreurs, sinon retourne 0.
 */

int	check_errors(int fd, char **line)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(*line);
		*line = 0;
		return (0);
	}
	return (1);
}

/*
	!*line <=> line[0] == '\0' <=> line[0] == 0
	line = 0 <=> line = NULL
	error est initialsé à 1
	error = -1 si read renvoie -1
	error = 0 si read renvoie 0
	if(error == 0 && *!line) <=> le fichier est vide => return (NULL)
*/

char	*get_next_line(int fd)
{
	static char		*line;
	char			*result;
	int				error;

	error = check_errors(fd, &line);
	if (error == 0)
		return (NULL);
	line = read_fd(line, fd, &error);
	if (error == -1 || (error == 0 && !*line))
	{
		free(line);
		line = 0;
		return (NULL);
	}
	if (!line)
		return (NULL);
	result = create_result(line);
	if (!result)
	{
		line = 0;
		free(line);
	}
	line = create_nextline(result, line);
	return (result);
}
