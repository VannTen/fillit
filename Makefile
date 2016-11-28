#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/24 14:11:20 by mgautier          #+#    #+#             *#
#*   Updated: 2016/11/28 12:28:58 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

# Project-specific variables

NAME = fillit
LIB_NAME = ft
SRC = $(PARSER_SRC) $(TEST_SRC)
PARSER_SRC = ft_file_reader.c ft_error.c ft_validate.c ft_checker.c
TEST_SRC = maintest.c ft_test.c
LIB_PATH = libft

# Unchanged variables

SRC_PATH = srcs
TEST_PATH = test
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
CPPFLAGS = -iquote $(INC_PATH) -iquote $(LIB_PATH)
LDLIBS = -l$(LIB_NAME)
LDFLAGS = -L$(LIB_PATH)

# V paths

vpath %.h $(INC_PATH)
vpath %.c $(SRC_PATH) $(TEST_PATH)
vpath %.o $(OBJ_PATH)
vpath %.a $(LIB_PATH)

# Special targets

.PHONY: all clean fclean re libclean $(LDLIBS)

.SECONDARY: $(OBJ)

# Mandatory rules

all: $(LDLIBS) $(NAME) 

clean: 
	@$(RM) $(OBJ_PATH) 2> /dev/null || true
	@$(RM) $(OBJ)

fclean: clean libclean
	$(RM) $(NAME)

re: fclean all

# Explicit rules

$(NAME): $(OBJ) | $(OBJ_PATH)
	$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@
	mv -f -t $| $^ 2> /dev/null | true

$(LDLIBS):
	$(MAKE) -C $(LIB_PATH)

$(OBJ_PATH):
	mkdir $@

libclean:
	$(MAKE) $(MAKECMDGOALS) -C $(LIB_PATH)
