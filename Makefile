NAME = pipex
OBJS = multi_pipe.o pipex_utils.o del.o close_pipe.o pipe_info.o command_info.o\
main.o
SRCS = multi_pipe.c pipex_utils.c del.c close_pipe.c pipe_info.c command_info.c\
main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

Libft: 
	make -C libft
.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME}: Libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean:
				make -C libft clean
				rm -f ${OBJS}

fclean:         
				make -C libft fclean
	        	rm -f ${OBJS}
				rm -f ${NAME}

re:             fclean all

.PHONY:         all clean fclean re Libft
