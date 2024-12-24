# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 15:41:58 by dmendoza          #+#    #+#              #
#    Updated: 2024/12/24 16:33:54 by dmendoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

CUR_DIR = $(shell pwd)

SRCS 	= $(CUR_DIR)/ft_isalnum.c  \
	$(CUR_DIR)/ft_isalpha.c  \
	$(CUR_DIR)/ft_isdigit.c  \
	$(CUR_DIR)/ft_isascii.c  \
	$(CUR_DIR)/ft_isprint.c  \
	$(CUR_DIR)/ft_strlen.c  \
	$(CUR_DIR)/ft_toupper.c  \
	$(CUR_DIR)/ft_tolower.c  \
	$(CUR_DIR)/ft_strlcat.c  \
	$(CUR_DIR)/ft_strlcpy.c  \
	$(CUR_DIR)/ft_strncmp.c  \
	$(CUR_DIR)/ft_strchr.c  \
	$(CUR_DIR)/ft_strrchr.c  \
	$(CUR_DIR)/ft_strnstr.c  \
	$(CUR_DIR)/ft_memset.c  \
	$(CUR_DIR)/ft_memcpy.c  \
	$(CUR_DIR)/ft_memmove.c  \
	$(CUR_DIR)/ft_memcmp.c  \
	$(CUR_DIR)/ft_memchr.c  \
	$(CUR_DIR)/ft_bzero.c  \
	$(CUR_DIR)/ft_atoi.c  \
	$(CUR_DIR)/ft_calloc.c \
	$(CUR_DIR)/ft_strdup.c \
	$(CUR_DIR)/ft_substr.c \
	$(CUR_DIR)/ft_strjoin.c \
	$(CUR_DIR)/ft_strtrim.c \
	$(CUR_DIR)/ft_split.c \
	$(CUR_DIR)/ft_itoa.c \
	$(CUR_DIR)/ft_strmapi.c \
	$(CUR_DIR)/ft_striteri.c \
	$(CUR_DIR)/ft_putchar_fd.c \
	$(CUR_DIR)/ft_putstr_fd.c \
	$(CUR_DIR)/ft_putendl_fd.c \
	$(CUR_DIR)/ft_putnbr_fd.c

OBJS 	= $(SRCS:.c=.o)

CLIB	= ar rcs

CC	= cc

RM	= rm -f

CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		$(CLIB) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
