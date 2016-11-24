#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/04 13:12:11 by mgautier          #+#    #+#             *#
#*   Updated: 2016/11/24 16:47:39 by mgautier         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

LIB = ft
NAME = lib$(LIB).a
OBJ = $(PART_1) $(PART_2) $(PART_3)
PART_1 = ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
		 ft_strncat.o ft_strlcat.o ft_strcmp.o ft_strncmp.o ft_memset.o \
		 ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o \
		 ft_memcmp.o ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o \
		 ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o \
		 ft_isprint.o ft_toupper.o ft_tolower.o
PART_2 = ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o \
		 ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o \
		 ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
		 ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o \
		 ft_putchar_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o
PART_3 = ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o \
		 ft_lstmap.o ft_lstcheck.o ft_add_end_list.o
TEST_OBJ = main.o tests.o list_test.o
TEST_NAME = my_test
SRC_DIR = .
HEADERS_DIR = .
OBJ_DIR = ./bin
TEST_DIR = ./test
AR = ar 
ARFLAGS = rc
CC = gcc
HEADERS = libft.h
HEADERS_TEST = tests.h
CFLAGS = -Wall -Wextra -Werror 
CPPFLAGS = -I $(HEADERS_DIR) -I $(TEST_DIR)
VPATH = ./test

vpath %.h $(HEADERS_DIR)
vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $?
	@ranlib $@

clean:
	@$(RM) $(OBJ)

fclean: clean cleantest
	@$(RM) $(NAME)

re: fclean all

# 
# Implicit rules
#

%.o: %.c $(HEADERS) 
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

#
# Rules for test
#

cleantest:
	@$(RM) $(TEST_NAME) $(TEST_OBJ)

retest: fclean test

test: $(TEST_NAME)

$(TEST_NAME): $(NAME) $(TEST_OBJ) $(HEADERS_TEST)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -L. -l$(LIB) $(TEST_OBJ)

