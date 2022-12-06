# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 13:24:34 by jojoo             #+#    #+#              #
#    Updated: 2022/04/09 19:42:21 by jojoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = crs

INCLUDES = ./libft.h

RM = rm -f

SRCS_1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
SRCS_2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS = $(SRCS_1) $(SRCS_2)
OBJS = $(SRCS:.c=.o)
B_OBJS = $(BONUS:.c=.o)


OBJS = $(SRCS:.c=.o) $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) 
	$(AR) $(ARFLAGS) $@ $^
bonus : $(OBJS) $(B_OBJS)
	make all

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<
clean :
	$(RM) $(OBJS) $(B_OBJS)
fclean : clean
	$(RM) $(OBJS) $(B_OBJS) $(NAME)
re : fclean all



