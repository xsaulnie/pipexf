/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:02:09 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/28 16:02:10 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe0(int **pfd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i == 0)
			close(pfd[0][0]);
		else
		{
			close(pfd[i][0]);
			close(pfd[i][1]);
		}
		i++;
	}
}

void	close_pipe(int ind, int **pfd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i == ind - 1)
			close(pfd[i][1]);
		else if (i == ind)
			close(pfd[i][0]);
		else
		{
			close(pfd[i][0]);
			close(pfd[i][1]);
		}
		i++;
	}
}

void	close_all_pipe(int **pfd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		close(pfd[i][0]);
		close(pfd[i][1]);
		i++;
	}
}
