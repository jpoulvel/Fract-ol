# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 14:02:55 by jpoulvel          #+#    #+#              #
#    Updated: 2019/08/29 17:25:17 by jpoulvel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS_DIR = srcs/
OBJ_DIR = objects/
LIB_DIR = libft/

SRCS_NAME = main.c \
	   draw_fractals.c \
	   julia.c \
	   mandelbrot.c \
	   init.c \
	   get_controls.c \
	   terminate.c \
	   change_appearance.c \
	   colors.c \
	   checking_functions.c \
	   other_fractals.c
OBJ_NAME = $(SRCS_NAME:.c=.o)
INCL = fractol.h \
	   $(LIB_DIR)libft.a \

SRCS = $(patsubst %,$(SRCS_DIR)%, $(SRCS_NAME))
OBJ = $(patsubst %,$(OBJ_DIR)%, $(OBJ_NAME))

CC = gcc -g
FLAGS = -Wall -Wextra -Werror -I $(INCL) $(MLXFLAGS)
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lpthread -O3

all: Makefile $(NAME)

$(NAME): FORCE LIB $(OBJ)
	@gcc -o $(NAME) $(FLAGS) $(OBJ)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $<

LIB:
	@$(MAKE) -C $(LIB_DIR)

clean:
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean $(NAME)

san : FORCE LIB $(OBJ)
	@gcc -o $(NAME) -fsanitize=address $(FLAGS) $(OBJ)

FORCE:

.PHONY: all clean fclean re FORCE
