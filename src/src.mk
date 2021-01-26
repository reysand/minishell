# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhelena <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 13:04:58 by fhelena           #+#    #+#              #
#    Updated: 2021/01/26 13:35:29 by fhelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			= src
BUILTINS_DIR	= builtins

SRC_SRCS		= main.c	\
				  free.c

-include		$(SRC_DIR)/$(BUILTINS_DIR)/builtins.mk

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_SRCS))	\
				  $(addprefix $(SRC_DIR)/, $(BUILTINS))
