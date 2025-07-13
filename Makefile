# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 15:41:58 by dmendoza          #+#    #+#              #
#    Updated: 2025/07/13 16:24:15 by dmendoza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a

SRCS 	= ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strlcpy.c  \
	  ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_memset.c \
	  ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memchr.c ft_bzero.c ft_atoi.c \
	  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	  ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	  ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	  ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c get_next_line.c \
	  ft_putchar.c ft_putstr.c ft_printf.c ft_printf_utils.c printf_print.c \
	  ft_strtok.c ft_atof.c ft_isspace.c ft_strndup.c

OBJS 	= $(SRCS:.c=.o)

INCLUDES = libft.h Makefile

CLIB	= ar rcs

CC	= cc

RM	= rm -f

CFLAGS 	= -Wall -Wextra -Werror

%.o:	%.c
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(INCLUDES) $(OBJS)
		@echo "Building libft..."
		@$(CLIB) -o $(NAME) $(OBJS)
		@echo "...libft built successfully."

all:	$(NAME)

clean:
		@echo "Cleaning objects..."
		@$(RM) $(OBJS)
		@echo "...objects cleansed."

fclean: 	clean
		@echo "Removing library file..."
		@$(RM) $(NAME)
		@echo "...library file removed."

re: 		fclean all

.PHONY:		all clean fclean re bonus
