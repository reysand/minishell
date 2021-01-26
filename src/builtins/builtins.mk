# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    builtins.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhelena <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 13:05:06 by fhelena           #+#    #+#              #
#    Updated: 2021/01/26 13:35:15 by fhelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUILTINS_SRCS	= echo.c	\
				  cd.c		\
				  setenv.c	\
				  unsetenv.c\
				  env.c		\
				  exit.c

BUILTINS		= $(addprefix $(BUILTINS_DIR)/, $(BUILTINS_SRCS))
