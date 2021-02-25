# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 13:04:58 by fhelena           #+#    #+#              #
#    Updated: 2021/02/24 14:49:09 by fhelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
BUILTINS_DIR	= $(SRC_DIR)/builtins
VPATH			+= $(OBJ_DIR)/$(SRC_DIR)

# Source Files
SRC_SRCS		= main.c

-include		$(BUILTINS_DIR)/builtins.mk

SRC				= $(addprefix $(SRC_DIR)/, $(SRC_SRCS)) $(BUILTINS)
