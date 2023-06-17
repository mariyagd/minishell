# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 12:23:37 by mdanchev          #+#    #+#              #
#    Updated: 2023/06/17 09:27:01 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #
GREEN 		= \033[32;6m
COLOR_END 	= \033[0m
MAGNETA		:= $(shell tput setaf 5)
YELLOW		:= $(shell tput setaf 3)
RESET		:= $(shell tput sgr0)

SRCS		= main.c \
			  utils.c \
			  malloc_error/malloc_error_print_message.c\
			  global_variable/init_global.c \
			  global_variable/increment_shlvl.c \
			  environnement/envp_routine.c \
			  environnement/get_env.c \
			  is_smth/is_token.c \
			  is_smth/is_operator.c \
			  is_smth/is_dollar.c \
			  is_smth/is_quote.c \
			  is_smth/is_white_space.c \
			  is_smth/is_question.c \
			  is_smth/is_numeric.c \
			  signal_handler/signal_handlers.c \
			  signal_handler/init_sigset.c \
			  signal_handler/pipex_handler.c \
			  tokens/token_routine.c \
			  tokens/token_routine_set_id.c \
			  tokens/token_routine_delete.c \
			  parsing/parsing.c \
			  parsing/syntax_errors.c\
			  parsing/syntax_errors_print_message.c \
			  parsing/token_extraction.c\
			  parsing/here_doc.c \
			  parsing/here_doc_check_if_quoted_keyword.c \
			  parsing/here_doc_quoted_keyword.c \
			  parsing/here_doc_unquoted_keyword.c \
			  parsing/delete_all_heredocs.c \
			  parsing/expansion.c \
			  parsing/expansion_helper.c \
			  parsing/expansion_dollar_conditions.c \
			  parsing/expansion_expand_var_helper.c \
			  parsing/expansion_looping.c \
			  parsing/expansion_trim_dollar.c \
			  parsing/expansion_join_tokens.c \
			  parsing/quote_removing.c \
			  command_struct/init_cmd.c \
			  command_struct/init_cmd_cmd.c \
			  command_struct/init_cmd_redir.c \
			  command_struct/free_cmd.c \
			  redirections/do_redirections.c \
			  redirections/loop_redirections.c \
			  redirections/restaure_fds.c \
			  execution/execution.c \
			  execution/pipex.c \
			  execution/pipex_helper.c \
			  execution/get_path.c \
			  execution/search_path_in_env_table.c \
			  execution/copy_env_tab.c\
			  execution/exec_one_cmd.c \
			  execution/exec_builtins.c \
			  execution/exec_bin.c \
			  builtins/exit.c \
			  builtins/int_min_max.c \
			  builtins/env.c \
			  builtins/echo.c \
			  builtins/pwd.c \
			  builtins/cd.c \
			  builtins/export.c \
			  builtins/unset.c \
			  builtins/export_unset_helper.c \


OBJS		= ${SRCS:.c=.o}

NAME		= minishell

CC			= gcc

RM			= rm -f

HEADERS		= minishell.h

LIBFT_FOLD	= libft

CFLAGS		+= -Wall -Wextra -Werror

SANITIZE	?= 0

ifeq ($(SANITIZE), 1)
CFLAGS += -g3 -fsanitize=address
CFLAGS += -fno-omit-frame-pointer
$(info $(YELLOW) fsanitize active$(RESET))
else
$(info $(MAGNETA) NO SANITIZER$(RESET))
endif

CFLAGS		+= -I. -Ilibft/includes
LIBFT		= -L./libft -lft

ifeq ($(USER), margaritamakarova)
CFLAGS		+= -I/opt/homebrew/opt/readline/include
READLINE 	= -L/opt/homebrew/opt/readline/lib -lreadline
else ifeq ($(USER), mariyadancheva)
CFLAGS		+= -I/opt/homebrew/Cellar/readline/8.2.1/include
READLINE	= -L/opt/homebrew/Cellar/readline/8.2.1/lib -lreadline
else
CFLAGS		+= -I$(HOME)/.brew/opt/readline/include
READLINE	=  -L$(HOME)/.brew/opt/readline/lib -lreadline
endif

.SUFFIXES: .c .o .h

.c.o:
	@ ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADERS}
	@		${MAKE} -C ${LIBFT_FOLD}
	@		${CC} ${CFLAGS} ${LIBFT} ${READLINE} -o ${NAME} ${OBJS}
	@echo	"${YELLOW} Compilation ${NAME} done ${RESET}"

all: ${NAME}

#all: norminette ${NAME}

#norminette:
#	@		norminette ${SRCS} ${HEADERS}
#	@echo "${GREEN} Norminette minishell done ${COLOR_END}"

clean:
	@		${MAKE} -C ${LIBFT_FOLD} clean
	@		${RM} ${OBJS}
	@echo	"${GREEN} Clean object files done ${COLOR_END}"

fclean:		clean
	@		${MAKE} -C ${LIBFT_FOLD} fclean
	@		${RM} ${NAME}
	@echo "${GREEN} Clean ${NAME} done ${COLOR_END}"

re:			fclean all

.PHONY: all clean fclean re
