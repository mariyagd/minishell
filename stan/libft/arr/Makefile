# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 22:03:28 by pmarquis          #+#    #+#              #
#    Updated: 2023/02/26 17:22:04 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean mrproper re

NAME = libftarr.a

LIBFTDIR = ..

# options

OPT_DEBUG ?= 1
export OPT_DEBUG

# end options

CC = gcc

ifeq ($(OPT_DEBUG),1)
CFLAGS = -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer
else
CFLAGS = -Wall -Wextra -Werror
endif

INC = ft_arr.h $(LIBFTDIR)/libft.h
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

DEFINES =

ifeq ($(OPT_DEBUG),0)
DEFINES += -DNDEBUG
endif

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) -I$(LIBFTDIR) -o $@ $<

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

mrproper: fclean
	rm -f cscope.* tags

re: fclean all

### deps
$(OBJ): $(INC)
