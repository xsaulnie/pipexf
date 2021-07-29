/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:02:51 by xsaulnie          #+#    #+#             */
/*   Updated: 2021/07/29 11:39:24 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *menv[])
{
	t_pipe	*inf;
	int		last_ret;

	if (argc < 5)
		return (1);
	inf = pipe_info(argc);
	if (inf == NULL)
		return (1);
	create_pipes(argc - 3, inf->pfd);
	mpipex(inf, argv, menv);
	close_all_pipe(inf->pfd, argc - 3);
	last_ret = wait_all_proc(inf);
	del_inf(inf);
	return (last_ret);
}
