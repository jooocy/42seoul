# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 20:46:40 by jojoo             #+#    #+#              #
#    Updated: 2022/11/08 05:48:59 by jojoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rc

BONUS = bonus

SRCS = push_swap.c initialization.c operation.c libft.c do_algorithm.c push_swap_utility.c size_any_sort.c

BONUS_SRCS = push_swap.c

OBJ = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

RM = rm -f

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(BONUS) : $(BONUS_OBJ)
	$(AR) $(BONUS) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJ)

clean :
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY :	all clean fclean re
