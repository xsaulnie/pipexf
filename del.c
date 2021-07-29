/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:02:39 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/29 11:27:18 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	del_dtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_del(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	del_dtabi(int **tab, int n)
{
	int	i;

	i = 0;
	while (tab[i] != NULL && i < n)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_del_cmd(t_command *cmd)
{
	free(cmd);
	cmd = NULL;
}

void	del_cmd(t_command *cmd_info, int mod)
{
	if (cmd_info->argv_cmd != NULL && mod >= 1)
		del_dtab(cmd_info->argv_cmd);
	if (cmd_info->cmd_list != NULL && mod >= 2)
		del_dtab(cmd_info->cmd_list);
	if (cmd_info->cmd != NULL && mod >= 3)
		ft_del(&(cmd_info->cmd));
	cmd_info->not_found = 0;
	if (cmd_info != NULL)
		ft_del_cmd(cmd_info);
}

void	del_inf(t_pipe *inf)
{
	close_all_pipe(inf->pfd, inf->argc - 3);
	if (inf->pfd != NULL)
		del_dtabi(inf->pfd, inf->argc - 3);
	if (inf->pid != NULL)
	{
		free(inf->pid);
		inf->pid = NULL;
	}
	inf->err = 0;
	inf->file_err = 0;
	if (inf != NULL)
	{
		free(inf);
		inf = NULL;
	}
}
