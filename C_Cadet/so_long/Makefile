# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 21:11:54 by jojoo             #+#    #+#              #
#    Updated: 2022/10/25 23:30:41 by jojoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= so_long
NAME_BONUS	= so_long_bonus

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
AR			= ar rcs
RM			= rm -f

SRC 		= so_long.c init_vars.c get_maps.c check_maps.c get_next_line.c get_next_line_utils.c render.c
OBJ			= $(SRC:.c=.o)
HEADER		= so_long.h

LIBFT		=libft
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -include $(HEADER) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(OBJ) -L$(LIBFT) -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	$(RM) $(OBJ)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re bonus