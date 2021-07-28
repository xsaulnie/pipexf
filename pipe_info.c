#include "pipex.h"

int	ini_pid(pid_t **pid, int argc)
{
	*pid = (pid_t *)malloc(sizeof (pid_t) * (argc - 3));
	if (*pid == NULL)
		return (1);
	return (0);
}

void	clean_del(int **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int	**ini_pipes(int n)
{
	int	**res;
	int	i;

	i = 0;
	res = (int **)malloc(sizeof(int *) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = (int *)malloc(sizeof(int) * 2);
		if (res == NULL)
		{
			clean_del(res, i);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

t_pipe	*pipe_info(int argc)
{
	t_pipe	*res;

	res = (t_pipe *)malloc(sizeof (t_pipe));
	if (res == NULL)
		return (NULL);
	res->argc = argc;
	res->pfd = ini_pipes(argc - 3);
	if (res->pfd == NULL)
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	if (ini_pid(&(res->pid), argc))
	{
		del_dtabi(res->pfd, argc - 3);
		free(res);
		res = NULL;
		return (NULL);
	}
	res->err = 0;
	return (res);
}

t_command	*read_command(char *arg_cmd, char *env[])
{
	t_command	*res;

	res = (t_command *)malloc(sizeof (t_command));
	if (res == NULL)
		return (NULL);
	res->not_found = 0;
	res->argv_cmd = ft_split(arg_cmd, ' ');
	if (res->argv_cmd == NULL)
	{
		del_cmd(res, 0);
		return (NULL);
	}
	if (ini_cmd_list(&(res->cmd_list), env))
	{
		del_cmd(res, 1);
		return (NULL);
	}
	res->cmd = check_cmd((res->argv_cmd)[0], res->cmd_list, &(res->not_found));
	if (res->cmd == NULL)
	{
		del_cmd(res, 2);
		return (NULL);
	}
	return (res);
}
