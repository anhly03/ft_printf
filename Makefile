# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phly <phly@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 13:43:11 by phly              #+#    #+#              #
#    Updated: 2025/07/24 23:49:00 by phly             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = 	cc
CFLAGS = 	-Wall -Wextra -Werror
NAME = 		libftprintf.a
SRCS =		test.c\
			

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# print-obj:
#   @echo $(OBJS)

