# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 13:14:25 by fhelena           #+#    #+#              #
#    Updated: 2021/01/16 18:17:36 by fhelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell
LIB				= libft.a

SRC_DIR			= src
INC_DIR			= include
BLD_DIR			= build
LIB_DIR			= libft

-include		$(SRC_DIR)/src.mk

SRCS			= $(SRC)
OBJS			= $(SRCS:%.c=$(BLD_DIR)/%.o)
DEPS			= $(SRCS:%.c=$(BLD_DIR)/%.d)

SHELL			= /bin/sh
CC				?= gcc
MKDIR			= mkdir -p
MAKE			= make -sC
RM				= rm -rf
NORME			= $(shell norminette $(SRCS) $(INC_DIR)\
				  | grep "Error" | wc -l | tr -d ' ')

CFLAGS			= -Wall -Wextra -Werror
DFLAGS			= -MT $@ -MMD -MP
IFLAGS			= -I $(INC_DIR) -I $(LIB_DIR)/$(INC_DIR)
LFLAGS			= -L $(LIB_DIR) -lft

R_CLEAN			= \033[K
C_RESET			= \033[00m
COLOR_R			= \033[31m
COLOR_G			= \033[32m
COLOR_Y			= \033[33m

PHONY			+= all
all:			libft $(NAME)
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

$(NAME):		$(OBJS)
	@printf "\r$(R_CLEAN)Linking: -> $(NAME)\n\t$(subst $(subst ,, ),\n\t,$^)\n"
	@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $@ $^

$(BLD_DIR):
	@$(MKDIR) $(dir $(OBJS))

$(BLD_DIR)/%.o:	%.c $(LIB_DIR)/$(LIB) | $(BLD_DIR)
	@printf "\r$(R_CLEAN)Assembling: $< -> $@"
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $< $(DFLAGS)

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
