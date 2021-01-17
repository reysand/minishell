SRC_DIR		= src/

SRC_SRCS	= main.c \
			  free.c

SRC			= $(addprefix $(SRC_DIR), $(SRC_SRCS))
