# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dt <dt@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 16:55:23 by dt                #+#    #+#              #
#    Updated: 2025/03/08 19:11:26 by dt               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_putnbr.c
OBJS	= $(SRCS:.c=.o)

# Rules of files
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rules of actions
.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all