# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 08:48:00 by wmillett          #+#    #+#              #
#    Updated: 2023/05/24 15:11:52 by wmillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Library Name ----------------------------
NAME = so_long
#Dependencies -----------------------------
LIBFT = libft
#Command variables ------------------------
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MK = mkdir -p
RM = rm -rf
USER = $(shell whoami)
MLXLB = -framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
#Sources directories ----------------------
MLX42 = ./MLX42/
INCDIR = inc
SRCDIR = src
LIBFT_A = libft.a
LIBFTDIR = libft
MLXDIR = ./MLX42/build/
DEBUG = DEBUG_SO_LONG
LIBFT = $(addprefix $(LIBFTDIR)/, $(LIBFT_A))
SRC = main.c pars_maps.c error.c utils.c utils_read.c window.c init_temp.c render_map.c utils_mem.c error_rend.c utils_check.c handle_exit.c init_temp_extra.c render_items.c
VPATH = ${SRCDIR}
#Colours -----------------------------------
B_BLUE='\033[1;34m'
RED=\033[0;31m
B_GREEN=\033[1;32m
COLOUR_END=\033[0m
#Object directories ------------------------
OBJDIR = obj
OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})
#Rules -------------------------------------
${OBJDIR}/%.o : %.c
	@${CC} ${CFLAGS} -I${INCDIR} -Ilibft/inc -Imlx42 -c $< -o $@
all: MLX $(NAME)
$(NAME): $(OBJDIR) $(OBJS)
	@make -C $(LIBFTDIR)
	@$(CC) ${CFLAGS} $(MLXLB) $(OBJS) -L$(dir $(LIBFT)) -lft -o $(NAME)
	@echo "$(B_GREEN)so_long has been created 🦊$(COLOUR_END)!"
MLX:
	@if [ ! -d "./MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git ./MLX42; fi
	@if [ ! -d "./MLX42/build" ]; then (cd ./MLX42 && cmake -B build && cmake --build build -j4); fi
MLX_fclean: 
	@if [ -d "./MLX42" ]; then $(RM) ./MLX42; fi
MLX_clean: 
	@if [ -d "./MLX42" ]; then make -C $(MLXDIR) clean; fi
$(OBJDIR):
	@$(MK) $(OBJDIR)
clean:
	@$(RM) $(OBJDIR)
	@$(MAKE) MLX_clean;
	@make -C $(LIBFTDIR) clean
fclean: clean MLX_fclean
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)so_long has been deleted 🗑️$(COLOUR_END)"
re: fclean all
# debug: MLX
# 	@make -C $(LIBFTDIR)
# 	@$(CC) -g ${CFLAGS} $(MLXLB) $(OBJS) -L$(dir $(LIBFT)) -lft -o $(DEBUG)
.PHONY: all clean fclean re MLX_clean MLX_clean MLX
