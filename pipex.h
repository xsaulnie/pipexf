#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

struct	s_pipe
{
	int		argc;
	int		**pfd;
	pid_t	*pid;
	int		err;
}	t_pipe;

struct	s_command
{
	char	**argv_cmd;
	char	**cmd_list;
	char	*cmd;
	int		not_found;
}	t_command;

//multi-pipe

int			cmd_ini(t_pipe *inf, char *argv[], char *menv[]);
void		multy_pipe(t_pipe *inf, char *argv[], char *menv[]);
int			cmd_last(t_pipe *inf, char *argv[], char *menv[]);
int			mpipex(t_pipe *inf, char *argv[], char *menv[]);

//pipex_utils

void		wait_cmd(int n, int *status);
void		create_pipes(int n, int **pfd);
void		put_err_message(char *env[], char *msg, char *name);
void		put_shell_type(char *env[]);

//del

void		del_dtab(char **tab);
void		del_dtabi(int **tab, int n);
void		ft_del_cmd(t_command *cmd);
void		del_cmd(t_command *cmd_info, int mod);
void		del_inf(t_pipe *inf);

//close_pipe

void		close_pipe0(int **pfd, int n);
void		close_pipe(int ind, int **pfd, int n);
void		close_all_pipe(int **pfd, int n);

//pipe_infoo

int			ini_pid(pid_t **pid, int argc);
int			**ini_pipes(int n);
t_pipe		*pipe_info(int argc);
t_command	*read_command(char *arg_cmd, char *env[]);

//command_info

int			ini_cmd_list(char ***cmd_list, char *env[]);
char		*check_list(char **cmd_list, char *slash_name, int *not_found);
char		*check_cmd(char *name, char **cmd_list, int *not_found);
int			run_cmd(char *arg_cmd, char *env[], int *err);
#endif
