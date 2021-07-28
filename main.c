#include "pipex.h"

int	main(int argc, char *argv[], char *menv[])
{
	t_pipe	*inf;
	int		status;
	int		last_ret;

	status = 0;
	last_ret = 1;
	if (argc < 5)
		return (1);
	inf = pipe_info(argc);
	if (inf == NULL)
		return (1);
	create_pipes(argc - 3, inf->pfd);
	mpipex(inf, argv, menv);
	close_all_pipe(inf->pfd, argc - 3);
	waitpid((inf->pid)[argc - 4], &status, WUNTRACED);
	if (WIFEXITED(status))
		last_ret = WEXITSTATUS(status);
	wait_cmd(argc - 4, &status);
	if (inf->err)
		last_ret = 127;
	del_inf(inf);
	return (last_ret);
}
