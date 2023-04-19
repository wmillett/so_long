# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 08:48:00 by wmillett          #+#    #+#              #
#    Updated: 2023/04/18 21:58:19 by wmillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Library Name ----------------------------
NAME = so_long
#Dependencies -----------------------------
LIBFT = libft
#Command variables ------------------------
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MK = mkdir -p
RM = rm -rf
USER = $(shell whoami)
MLX42 = -framework Cocoa -framework OpenGL -framework IOKit MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
#Sources directories
INCDIR = inc
SRCDIR = src
LIBFT_A = libft.a
LIBFTDIR = libft
LIBFT = $(addprefix $(LIBFTDIR)/, $(LIBFT_A))
SRC = main.c maps.c error.c utils.c 
VPATH = ${SRCDIR}
#Object directories
OBJDIR = obj
OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})
${OBJDIR}/%.o : %.c
	${CC} ${FLAGS} -I${INCDIR} -Ilibft/inc -Imlx42 -c $< -o $@
all: $(NAME)
$(NAME): $(OBJDIR) $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) ${FLAGS} $(MLX42) $(OBJS) -L$(dir $(LIBFT)) -lft -o $(NAME)
$(OBJDIR):
	$(MK) $(OBJDIR)
clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean
re: fclean all
