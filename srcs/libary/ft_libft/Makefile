# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 01:27:40 by segurbuz          #+#    #+#              #
#    Updated: 2023/01/04 01:27:41 by segurbuz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			= ft_isdigit.c \
					ft_isalpha.c \
					ft_strlen.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_isalnum.c \
					ft_memset.c \
					ft_memcpy.c	\
					ft_memcmp.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_bzero.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_atoi.c  \
					ft_calloc.c \
					ft_strdup.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_itoa.c \
					ft_split.c \
					ft_strtrim.c \
					ft_striteri.c \
					ft_strmapi.c \

OBJS			= $(SRCS:%.c=%.o)

FLAGS			= -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
