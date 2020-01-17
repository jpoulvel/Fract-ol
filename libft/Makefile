# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 11:30:42 by jpoulvel          #+#    #+#              #
#    Updated: 2020/01/17 12:15:21 by jpoulvel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c \
	   ft_error.c \
	   ft_sqrt.c \
	   ft_power.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_strcmp.c \
	   ft_sqrt.c \
	   ft_strncmp.c \
	   ft_abs.c \

OBJ = $(SRCS:.c=.o)

INCL = libft.h

FLAGS = -Wall -Wextra -Werror -I $(INCL)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
