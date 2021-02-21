# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    builtins.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 13:05:06 by fhelena           #+#    #+#              #
#    Updated: 2021/02/21 13:10:01 by fhelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source Files
BUILTINS_SRCS	= echo.c	\
				  cd.c		\
				  setenv.c	\
				  unsetenv.c\
				  env.c		\
				  exit.c

BUILTINS		= $(addprefix $(BUILTINS_DIR)/, $(BUILTINS_SRCS))
