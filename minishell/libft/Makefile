# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 12:21:59 by mdanchev          #+#    #+#              #
#    Updated: 2023/06/16 08:43:36 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

SRCS_LIBFT = 		libft/ft_memset.c \
					libft/ft_bzero.c \
					libft/ft_memcpy.c \
					libft/ft_isalpha.c \
					libft/ft_memmove.c \
					libft/ft_memchr.c \
					libft/ft_isdigit.c \
					libft/ft_isalnum.c \
					libft/ft_isascii.c \
					libft/ft_isprint.c \
					libft/ft_strlen.c \
					libft/ft_memcmp.c \
					libft/ft_strlcpy.c \
					libft/ft_strcpy.c \
					libft/ft_strlcat.c \
					libft/ft_strchr.c \
					libft/ft_strrchr.c \
	   				libft/ft_strnstr.c \
					libft/ft_strncmp.c \
					libft/ft_toupper.c \
					libft/ft_tolower.c \
					libft/ft_atoi.c \
					libft/ft_calloc.c \
					libft/ft_strdup.c \
					libft/ft_substr.c \
					libft/ft_strjoin.c \
					libft/ft_strtrim.c \
					libft/ft_split.c \
					libft/ft_itoa.c \
					libft/ft_strmapi.c \
					libft/ft_striteri.c \
					libft/ft_putchar_fd.c \
					libft/ft_putnbr_fd.c \
					libft/ft_putstr_fd.c \
					libft/power.c \
					libft/ft_atoi_base.c \
					libft/ft_strcspn.c \
					libft/ft_strspn.c \
					libft/ft_strpbrk.c \
					libft/del.c \
					libft/str_lowercase.c 
		
SRCS_LSTCHAINE = 	libft/ft_lstnew.c \
					libft/ft_lstadd_front.c \
					libft/ft_lstsize.c \
					libft/ft_lstlast.c \
					libft/ft_lstadd_back.c \
					libft/ft_lstdelone.c \
					libft/ft_lstclear.c \
					libft/ft_lstiter.c \
					libft/ft_lstmap.c

SRCS_PRINTF = 		ft_printf/ft_printf.c \
					ft_printf/ft_dprintf.c \
					ft_printf/ft_printf_char.c \
					ft_printf/ft_printf_str.c \
					ft_printf/ft_printf_int.c \
					ft_printf/ft_count_int.c \
					ft_printf/ft_put_unsnbr_fd.c \
					ft_printf/ft_printf_unsint.c \
					ft_printf/ft_count_unsigned_int.c \
					ft_printf/ft_printf_address.c \
					ft_printf/ft_printf_hexa.c

SRCS_GNL = 			get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \
					get_next_line/get_next_line_bonus.c \



OBJS =  ${SRCS_LIBFT:.c=.o} ${SRCS_LSTCHAINE:.c=.o} ${SRCS_PRINTF:.c=.o} ${SRCS_GNL:.c=.o} \
		${SRCS_RANK02:.c=.o}

NAME = libft.a

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

GREEN = \033[32;6m

COLOR_END = \033[0m

.c.o:
	@	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

#all:	norminette ${NAME}

norminette:
	 norminette ${SRCS} ${HEADERS}
	@echo "${GREEN} Norminette libft done ${COLOR_END}"


$(NAME): ${OBJS}
	@	ar rcs ${NAME} ${OBJS}
	@echo "${GREEN} Compilation ${NAME} done ${COLOR_END}"

clean:
	@	${RM} ${OBJS}

fclean:	clean
	@	${RM} ${NAME}
	@echo "${GREEN} Clean ${NAME} done ${COLOR_END}"

re:		fclean all

.PHONY:	all clean fclean re
