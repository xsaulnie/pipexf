/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:03:02 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/28 16:06:41 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_ini(t_pipe *inf, char *argv[], char *menv[])
{
	int	fi;

	(inf->pid)[0] = fork();
	if ((inf->pid)[0] == 0)
	{
		fi = open(argv[1], O_RDONLY);
		if (fi == -1)
			return (1);
		close_pipe0(inf->pfd, inf->argc - 3);
		dup2(fi, 0);
		close(fi);
		dup2((inf->pfd)[0][1], 1);
		close((inf->pfd)[0][1]);
        if (run_cmd(argv[2], menv, &(inf->err)))
            return (1);
	}
	return (0);
}

int multy_pipe(t_pipe *inf, char *argv[], char *menv[])
{
	int	i;
	int	n;

	i = 1;
	n = inf->argc - 5;
	while (i < n + 1)
	{
		(inf->pid)[i] = fork();
		if ((inf->pid)[i] == 0)
		{
			close_pipe(i, inf->pfd, n + 2);
			dup2((inf->pfd)[i - 1][0], 0);
			close((inf->pfd)[i - 1][0]);
			dup2((inf->pfd)[i][1], 1);
			close((inf->pfd)[i][1]);
			if (run_cmd(argv[i + 2], menv, &(inf->err)))
                return (1);
		}
		i++;
	}
    return (0);
}

int	cmd_last(t_pipe *inf, char *argv[], char *menv[])
{
	int	fo;

	(inf->pid)[inf->argc - 4] = fork();
	if ((inf->pid)[inf->argc - 4] == 0)
	{
		fo = open(argv[inf->argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (fo == -1)
			return (1);
		close_pipe(inf->argc - 4, inf->pfd, inf->argc - 3);
		close((inf->pfd)[inf->argc - 4][1]);
		dup2(fo, 1);
		close(fo);
		dup2((inf->pfd)[inf->argc - 5][0], 0);
		close((inf->pfd)[inf->argc - 5][0]);
		if (run_cmd(argv[inf->argc - 2], menv, &(inf->err)))
            return (2);
	}
	return (0);
}

int	mpipex(t_pipe *inf, char *argv[], char *menv[])
{
    if (cmd_ini(inf, argv, menv) == 1)
        inf->file_err = 1;
	if (multy_pipe(inf, argv, menv) == 1)
        inf->file_err = 1;
    if (cmd_last(inf, argv, menv) == 1)
        inf->file_err = 1;
	return (0);
}
