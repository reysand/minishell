# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 13:14:25 by fhelena           #+#    #+#              #
#    Updated: 2021/02/06 16:46:59 by fhelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell
LIB				= libft.a
CHANGELOG		= ChangeLog

SRC_DIR			= src
INC_DIR			= include
BLD_DIR			= build
LIB_DIR			= libft

-include		$(SRC_DIR)/src.mk

SRCS			= $(SRC)
OBJS			= $(SRCS:%.c=$(BLD_DIR)/%.o)
DEPS			= $(SRCS:%.c=$(BLD_DIR)/%.d)

SHELL			= /bin/bash
DATE			= date
CC				= gcc
MKDIR			= -mkdir -p
MAKE			= make -sC
RM				= -rm -rf
NORME			= $(shell norminette $(SRCS) $(INC_DIR)\
				  | grep "Error" | wc -l | tr -d ' ')

CFLAGS			= -Wall -Wextra -Werror
DEPFLAGS		= -MT $@ -MMD -MP
INCFLAGS		= -I $(INC_DIR) -I $(LIB_DIR)/$(INC_DIR)
LDFLAGS			= -L $(LIB_DIR)
LDLIBS			= -lft

R_CLEAN			= \033[K
C_RESET			= \033[00m
COLOR_R			= \033[31m
COLOR_G			= \033[32m

PHONY			+= all
all:			libft changelog $(NAME)
	@printf "$(COLOR_G)PASS:$(C_RESET)\t$(NAME)\n"

PHONY			+= libft
libft:
	@$(MAKE) $(LIB_DIR)

PHONY			+= norme
norme:
ifeq ($(NORME), 0)
	@printf "$(COLOR_G)PASS:$(C_RESET)\tnorminette\t[$(NAME)]\n"
else
	@printf "$(COLOR_R)PASS:$(C_RESET)\tnorminette\t[$(NAME)] [$(NORME)]\n"
endif

PHONY			+= check
check:			norme all
	@printf "$(COLOR_G)PASS:$(C_RESET)\tcheck\n"

PHONY			+= changelog
changelog:
	@$(DATE) >> $(CHANGELOG) && echo "" >> $(CHANGELOG)

$(NAME):		$(OBJS)
	@echo "" >> $(CHANGELOG)
	@printf "\r$(R_CLEAN)Linking: -> $@\n\t$(subst $(subst ,, ),\n\t,$^)\n"
	@$(CC) $(CFLAGS) $(INCFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(BLD_DIR)/%.o:	%.c $(LIB_DIR)/$(LIB)
	@$(MKDIR) $(@D)
	@$(shell git diff --stat | grep $< >> ChangeLog)
	@printf "\r$(R_CLEAN)Assembling: $< -> $@"
	@$(CC) $(CFLAGS) $(INCFLAGS) -o $@ -c $< $(DEPFLAGS)

PHONY			+= clean
clean:
	@$(MAKE) $(LIB_DIR) clean
	@$(RM) $(BLD_DIR)
	@printf "$(COLOR_G)PASS:$(C_RESET)\tmake clean\t[$(NAME)]\n"

PHONY			+= fclean
fclean:			clean
	@$(MAKE) $(LIB_DIR) fclean
	@$(RM) $(NAME)
	@printf "$(COLOR_G)PASS:$(C_RESET)\tmake fclean\t[$(NAME)]\n"

PHONY			+= re
re:				fclean all

-include $(wildcard $(DEPS))

.PHONY:			$(PHONY)
