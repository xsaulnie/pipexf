/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:05:32 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/28 16:05:33 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_cmd(int n, int *status)
{
	int	i;

	i = 0;
	while (i < n)
	{
		wait(status);
		i++;
	}
}

void	create_pipes(int n, int **pfd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pipe(pfd[i]);
		i++;
	}
}

void	put_err_message(char *env[], char *msg, char *name)
{
	put_shell_type(env);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
}

void	put_shell_type(char *env[])
{
	int	i;
	int	len;
	int	not_found;

	not_found = 1;
	i = 0;
	while (env[i] && not_found)
	{
		if (ft_strncmp(env[i], "SHELL=", 5) == 0)
		{
			not_found = 0;
			len = ft_strlen(env[i]);
			while (len >= 0 && env[i][len] != '/')
				len--;
			ft_putstr_fd(env[i] + len + 1, 2);
			ft_putstr_fd(": ", 2);
		}
		i++;
	}
	return ;
}
