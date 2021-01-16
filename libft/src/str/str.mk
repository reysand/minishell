# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    str.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhelena <fhelena@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/22 23:35:19 by fhelena           #+#    #+#              #
#    Updated: 2020/05/22 23:45:07 by fhelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STR_DIR		= src/str/

STR_SRCS	= ft_strcat.c \
			  ft_strchr.c \
			  ft_strclr.c \
			  ft_strcmp.c \
			  ft_strcpy.c \
			  ft_strdel.c \
			  ft_strdup.c \
			  ft_strequ.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strmap.c \
			  ft_strmapi.c \
			  ft_strncat.c \
			  ft_strncmp.c \
			  ft_strncpy.c \
			  ft_strnequ.c \
			  ft_strnew.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_strsplit.c \
			  ft_strstr.c \
			  ft_strsub.c \
			  ft_strtrim.c \
			  ft_wordcount.c

STR	= $(addprefix $(STR_DIR), $(STR_SRCS))