# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 11:55:15 by wmillett          #+#    #+#              #
#    Updated: 2023/05/18 15:20:09 by wmillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar -crs
MK = mkdir -p
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCDIR = inc
SRCDIR = src

SRC = 	ft_printf.c\
		ft_putadr.c\
		ft_puthex.c\
		ft_puthex_toupper.c\
		ft_unsigned_putnbr.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_strlen.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_strchr.c\
		ft_strdup.c\


VPATH = ${SRCDIR}


OBJDIR = obj
OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})

${OBJDIR}/%.o : %.c
	@${CC} ${FLAGS} -I${INCDIR} -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
$(OBJDIR):
	@$(MK) $(OBJDIR)

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re