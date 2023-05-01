SRCS	= main.c\
		  env_var.c\
		  env_key.c\
		  handler_ctr_c.c\
		  handler_ctr_d.c\
		  init_struc_env.c\
		  launch_setup.c\
		  complicated_split.c\
		  parsing_av.c\
		  free.c\

OBJS	= ${SRCS:.c=.o}

NAME	= minishell

CC		= gcc

RM		= rm -f

HEADERS		= minishell.h

INC_LIBFT	= libft

DEPS		= ${INC_LIBFT}/libft.h

CFLAGS		+= -Wall -Wextra -Werror -I. 

READLINE	= -lreadline

CFLAGS += -I$(HOME)/.brew/opt/readline/include
READLINE += -L$(HOME)/.brew/opt/readline/lib

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADERS}
			${MAKE} -C ${INC_LIBFT}
			${CC} ${CFLAGS} ${READLINE} -L ${INC_LIBFT} -lft -o ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}
			${RM}
			${MAKE} -C ${INC_LIBFT} clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
