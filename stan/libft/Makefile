# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapopor <srapopor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 22:29:10 by pmarquis          #+#    #+#              #
#    Updated: 2023/02/26 17:20:12 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mrproper

# OPTIONS

OPT_DEBUG ?= 0
export OPT_DEBUG

OPT_PREALLOC ?= 0
export OPT_PREALLOC

OPT_MEMLIST ?= 1
export OPT_MEMLIST

OPT_LINUX ?= 1
export OPT_LINUX

### end options

NAME = libft.a

CC = gcc

ifeq ($(OPT_DEBUG),1)
CFLAGS = -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer
else
CFLAGS = -Wall -Wextra -Werror
endif

INC = libft.h
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

DEFINES =

ifeq ($(OPT_DEBUG),0)
DEFINES += -DNDEBUG
endif

ifeq ($(OPT_PREALLOC),1)
DEFINES += -DPREALLOC
endif

ifeq ($(OPT_MEMLIST),0)
DEFINES += -DNMEMLIST
endif

ifeq ($(OPT_LINUX),1)
DEFINES += -DLINUX
endif

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) -o $@ $<

clean:
	rm -f *.o
	$(MAKE) -C arr $@
	$(MAKE) -C gnl $@
	$(MAKE) -C printf $@

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C arr $@
	$(MAKE) -C gnl $@
	$(MAKE) -C printf $@

re: fclean all

mrproper: fclean
	rm -f cscope.* tags
	$(MAKE) -C arr $@
	$(MAKE) -C gnl $@
	$(MAKE) -C printf $@

### deps
$(OBJ): $(INC)
