# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 17:37:29 by jojoo             #+#    #+#              #
#    Updated: 2022/10/12 16:17:20 by jojoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

SERVER_SRCS	= server.c
SERVER_SRCS_BONUS = server_bonus.c

CLIENT_SRCS = client.c
CLIENT_SRCS_BONUS = client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft.a

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

ifdef BNS
		SERVER_OBJECTS = $(SERVER_OBJS_BONUS)
		CLIENT_OBJECTS = $(CLIENT_OBJS_BONUS)
else
		SERVER_OBJECTS = $(SERVER_OBJS)
		CLIENT_OBJECTS = $(CLIENT_OBJS)
endif

.c.o :
	$(CC) $(CFLAGS) -c $< -I./ -o $(<:.c=.o)

$(SERVER) : $(SERVER_OBJECTS)
	make all -C $(LIBFT)
	gcc -o $(SERVER) $(SERVER_OBJECTS) -L./libft -lft

$(CLIENT) : $(CLIENT_OBJECTS)
	make all -C $(LIBFT)
	gcc -o $(CLIENT) $(CLIENT_OBJECTS) -L./libft -lft

$(NAME) : $(CLIENT) $(SERVER)

all : $(NAME)


clean :
	$(RM) *.o
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	$(RM) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

bonus:
		$(MAKE) BNS=1 all 

re : fclean all

.PHONY: all clean fclean re bonus
