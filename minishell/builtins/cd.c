/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:39:56 by mdanchev          #+#    #+#             */
/*   Updated: 2023/06/10 15:37:36 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static void	change_env_error(char *oldpwd, char *pwd, t_cmd *cmd)
{
	malloc_error_print_message("ft_strdup failed");
	if (oldpwd)
		free (oldpwd);
	if (pwd)
		free (pwd);
	free_and_exit_prog(&cmd, 1);
}

static void	change_env(char *oldpwd, char *pwd, t_cmd *cmd)
{
	t_env	*env;

	env = g_shell->env;
	while (env != NULL)
	{
		if (ft_strncmp(env->var_name, "OLDPWD", 7) == 0)
		{
			free(env->var_value);
			env->var_value = NULL;
			env->var_value = ft_strdup(oldpwd);
			if (!env->var_value)
				change_env_error(oldpwd, pwd, cmd);
		}
		if (ft_strncmp(env->var_name, "PWD", 4) == 0)
		{
			free(env->var_value);
			env->var_value = NULL;
			env->var_value = ft_strdup(pwd);
			if (!env->var_value)
				change_env_error(oldpwd, pwd, cmd);
		}
		env = env->next;
	}
	g_shell->exit_status = 0;
	return (free(oldpwd), free(pwd));
}

static void	print_chdir_error(char *arg, char *err)
{
	ft_dprintf(2, "minishell: cd: %s: ", arg);
	ft_dprintf(2, "%s\n", err);
	g_shell->exit_status = 1;
}

static int	change_dir(char *oldpwd, char *path)
{
	int	res;

	res = chdir(path);
	if (res == -1)
	{
		free(oldpwd);
		print_chdir_error(path, strerror(errno));
		return (0);
	}
	g_shell->exit_status = 0;
	return (1);
}

/* EST-CE QU'IL FAUT EXIT PROG SI OLDPWD ET PWD NE SE MALLOC PAS */
void	_cd(t_cmd *cmd)
{
	int		res;
	char	*oldpwd;
	char	*pwd;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
	{
		print_getcwd_error(strerror(errno));
		return ;
	}
	if (size_tab2d(cmd->cmd) == 1)
		res = change_dir(oldpwd, get_env_var_value("HOME"));
	else
		res = change_dir(oldpwd, cmd->cmd[1]);
	if (!res)
		return ;
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		free(oldpwd);
		print_getcwd_error(strerror(errno));
		return ;
	}
	change_env(oldpwd, pwd, cmd);
}
