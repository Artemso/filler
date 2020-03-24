# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solopov <solopov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/24 13:21:16 by solopov           #+#    #+#              #
#    Updated: 2020/03/24 13:27:24 by solopov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags 'n colors

CFLAGS		=	-O3 #-Wall -Wextra -Werror
GREEN		=	\033[0;32m
GREENB		=	\033[1;32m
RES			=	\033[0m
RED			=	\033[0;31m

# FILLER files

NAME				= asolopov.filler

FILLER_SRCS			= main.c

FILLER_FILES		= $(addprefix $(FILLER_DIR), $(FILLER_SRCS))

# Directories

FILLER_DIR			= ./srcs/
LIBFT_DIR			= ./libs/libft/
LIB_MLX_DIR			= ./libs/libmlx

# Libraries

LIBFT_NAME			= libft.a
MLX_NAME			= libmlx.a
MLX_A				= $(addprefix $(LIB_MLX_DIR), $(MLX_NAME))
LIBFT_A				= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBMLXFLAGS			= -I$(LIB_MLX_DIR) -L$(LIB_MLX_DIR) -lmlx -framework OpenGL -framework Appkit

# Includes
INCLUDES			= includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_NAME)
	@echo "$(RED)Compiling filler...$(RES)"
	@gcc -o $(NAME) $(CFLAGS) -I $(INCLUDES) $(FILLER_FILES) $(LIBFT_A)
	@echo "$(GREENB)$(NAME) $(GREEN)done.$(RES)"

$(LIBFT_NAME):
	@echo "$(RED)Compiling Libft Library$(RES)"
	@Make all -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"
	@echo "$(RED)Compiling MLX Library$(RES)"
	@Make all -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

clean:
	@echo "$(RED)Removing Object Files...$(RES)"
	@Make clean -C $(LIBFT_DIR)
	@Make clean -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

fclean: clean
	@echo "$(RED)Removing Executable & Library...$(RES)"
	@/bin/rm -f $(NAME)
	@Make fclean -C $(LIBFT_DIR)
	@Make fclean -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

re: fclean all