#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/24 14:11:20 by mgautier          #+#    #+#             *#
#*   Updated: 2016/11/24 18:41:02 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# Project-specific variables

NAME = fillit
LIB_NAME = ft
SRC = $(PARSER_SRC)
PARSER_SRC = ft_file_reader.c ft_error.c
LIB_PATH = libft

# Unchanged variables

SRC_PATH = srcs
OBJ = $(SRC:.c=.o)
OBJ_PATH = bin
INC_PATH = includes
LIB = lib$(LIB_NAME).a

# Variables used by implicit rules

export AR = ar
export ARFLAGS = rc
export CC = gcc
export CFLAGS = -Wall -Wextra -Werror
export RM = rm -Rf
CPPFLAGS = -I $(INC_PATH) -I $(LIB_PATH)
LDLIBS = -l$(LIB_NAME)
LDFLAGS = -L$(LIB_PATH)

# V paths

vpath %.h $(INC_PATH)
vpath %.c $(SRC_PATH)
vpath %.o $(OBJ_PATH)
vpath %.a $(LIB_PATH)

# Special targets

.PHONY: all clean fclean re libclean

# Mandatory rules

all: $(NAME)

clean: 
	$(RM) $(OBJ_PATH) 2> /dev/null || true

fclean: clean libclean
	$(RM) $(NAME)

re: fclean all

# Explicit rules

$(NAME): $(LDLIBS) $(OBJ)
	$(CC) $(LDFLAGS)  $^ -o $@

$(LDLIBS):
	$(MAKE) -C $(LIB_PATH)

libclean:
	$(MAKE) $(MAKECMDGOALS) -C $(LIB_PATH)

# Implicit rules

%.o: %.c %.h
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $(OBJ_PATH)/$@ $<
