# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 22:27:26 by pmarquis          #+#    #+#              #
#    Updated: 2023/02/26 17:20:38 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean mrproper re

# options

OPT_DEBUG ?= 0
export OPT_DEBUG

OPT_PREALLOC ?= 0
export OPT_PREALLOC

OPT_MEMLIST ?= 1
export OPT_MEMLIST

OPT_LINUX ?= 1
export OPT_LINUX

# end options

NAME = libftprintf.a

SRCDIR = .
LIBFTDIR = ..

CC = gcc

ifeq ($(OPT_DEBUG),1)
CFLAGS = -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer
else
CFLAGS = -Wall -Wextra -Werror
endif

INC	= $(wildcard $(SRCDIR)/*.h) $(LIBFTDIR)/libft.h
SRC = $(wildcard $(SRCDIR)/*.c)
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

INCLUDES = -I$(LIBFTDIR)

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

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
