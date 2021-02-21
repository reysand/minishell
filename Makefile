# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 13:14:25 by fhelena           #+#    #+#              #
#    Updated: 2021/02/20 20:56:13 by fhelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target Files
NAME			= minishell
LIB				= libft.a

# Directories
SRC_DIR			= src
INC_DIR			= include
LIB_DIR			= libft
BLD_DIR			= build
OBJ_DIR			= $(BLD_DIR)/objs
DEP_DIR			= $(BLD_DIR)/deps

-include		$(SRC_DIR)/$(SRC_DIR).mk

# Files
SRCS			= $(SRC)
OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS			= $(SRCS:%.c=$(DEP_DIR)/%.d)

# Programs
SHELL			= /bin/bash
CC				= gcc
MKDIR			= -mkdir -p
MAKE			= make -sC
RM				= -rm -rf

# Flags
CFLAGS			= -Wall -Wextra -Werror
DEPFLAGS		= -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
INCFLAGS		= -I $(INC_DIR) -I $(LIB_DIR)/$(INC_DIR)
LDFLAGS			= -L $(LIB_DIR)
LDLIBS			= -lft

# ANSI Escape Sequences
R_CLEAN			= \033[K
C_RESET			= \033[00m
COLOR_R			= \033[31m
COLOR_G			= \033[32m

PHONY			+= all
all:			libft $(NAME)
	printf "$(COLOR_G)PASS:$(C_RESET)\t$(NAME)\n"

PHONY			+= libft
libft:
	$(MAKE) $(LIB_DIR)

$(NAME):		$(OBJS)
	printf "\r$(R_CLEAN)Linking: -> $@\n\t$(subst $(subst ,, ),\n\t,$^)\n"
	$(CC) $(CFLAGS) $(INCFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o:	%.c $(DEP_DIR)/%.d $(LIB_DIR)/$(LIB)
	$(MKDIR) $(@D) $(dir $(DEPS))
	printf "\r$(R_CLEAN)Assembling: $< -> $@"
	$(CC) $(CFLAGS) $(INCFLAGS) -o $@ -c $< $(DEPFLAGS)

$(DEPS):

PHONY			+= clean
clean:
	$(MAKE) $(LIB_DIR) clean
	$(RM) $(BLD_DIR)
	printf "$(COLOR_G)PASS:$(C_RESET)\tmake clean\t[$(NAME)]\n"

PHONY			+= fclean
fclean:			clean
	$(MAKE) $(LIB_DIR) fclean
	$(RM) $(NAME)
	printf "$(COLOR_G)PASS:$(C_RESET)\tmake fclean\t[$(NAME)]\n"

PHONY			+= re
re:				fclean all

$(V).SILENT:

-include		$(wildcard $(DEPS))

.PHONY:			$(PHONY)
