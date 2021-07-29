/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:02:22 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/28 16:02:24 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ini_cmd_list(char ***cmd_list, char *env[])
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			*cmd_list = ft_split(env[i] + 5, ':');
			if (*cmd_list == NULL)
				return (1);
		}
		i++;
	}
	return (0);
}

char	*check_list(char **cmd_list, char *slash_name, int *not_found)
{
	char	*cmd;
	int		i;

	i = 0;
	while (cmd_list[i] != NULL)
	{
		 cmd = ft_strjoin(cmd_list[i], slash_name);
		 if (cmd == NULL)
			return (NULL);
		 if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		 ft_del(&cmd);
		 i++;
	}
	*not_found = 1;
	return (ft_emptystr());
}

char	*check_cmd(char *name, char **cmd_list, int *not_found)
{
	char	*slash_name;
	char	*res;

	*not_found = 0;
	if (access(name, F_OK | X_OK) == 0)
		 return (name);
	slash_name = ft_strjoin("/", name);
	if (slash_name == NULL)
		 return (NULL);
	res = check_list(cmd_list, slash_name, not_found);
	if (res == NULL)
		return (NULL);
	ft_del(&slash_name);
	if (*not_found)
		 return (ft_emptystr());
	else
		 return (res);
}

int	run_cmd(char *arg_cmd, char *env[], int *err)
{
	t_command	*cmd_info;

	cmd_info = read_command(arg_cmd, env);
	if (cmd_info == NULL)
		 return (1);
	if (cmd_info->not_found && !(*err))
	{
		 put_err_message(env, "command not found: ", cmd_info->argv_cmd[0]);
		 *err = 1;
		 del_cmd(cmd_info, 3);
		 return (1);
	}
	if (!(*err))
		execve(cmd_info->cmd, cmd_info->argv_cmd, env);
	del_cmd(cmd_info, 3);
	return (0);
}
