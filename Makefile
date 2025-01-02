# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 15:41:58 by dmendoza          #+#    #+#              #
#    Updated: 2025/01/02 17:49:58 by dmendoza         ###   ########.fr        #
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

BONUS	= 	$(CUR_DIR)/ft_lstnew_bonus.c \
		$(CUR_DIR)/ft_lstadd_front_bonus.c \
		$(CUR_DIR)/ft_lstlast_bonus.c \
		$(CUR_DIR)/ft_lstadd_back_bonus.c \
		$(CUR_DIR)/ft_lstdelone_bonus.c \
		$(CUR_DIR)/ft_lstclear_bonus.c \
		$(CUR_DIR)/ft_lstiter_bonus.c \
		$(CUR_DIR)/ft_lstmap_bonus.c \
		$(CUR_DIR)/ft_lstsize_bonus.c


BONUS_OBJS = $(BONUS:.c=.o)

CLIB	= ar rcs

CC	= cc

RM	= rm -f

CFLAGS 	= -Wall -Wextra -Werror

%.o:	%.c Makefile libft.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		$(CLIB) -o $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
		$(CLIB) $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re bonus
