# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaanni <mbaanni@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 09:42:52 by mbaanni           #+#    #+#              #
#    Updated: 2022/10/31 14:33:15 by mbaanni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c print_hexa.c
OBG = $(SRC:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME): $(OBG)
	@ar -rc $(NAME) $(OBG)
clean :
	@rm -rf *.o
fclean : clean
	@rm -rf libftprintf.a
re : fclean all

.PHONY : all clean fclean re