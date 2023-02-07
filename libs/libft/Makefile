# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 18:52:49 by lucperei          #+#    #+#              #
#    Updated: 2023/02/04 23:02:43 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

FLAGS = -Wall -Wextra -Werror -I./ -c

SRC = get_next_line.c \
	ft_strchr.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strjoin.c  \

OBJS = $(SRC:.c=.o)

HEADER = libft.h
RM = rm -f
AR = ar rc
CC = cc

$(NAME): $(OBJS) $(HEADER)
		$(CC) $(FLAGS) $(SRC)
		$(AR) $(NAME) $(OBJS)

all: $(NAME)
	
clean: 
		$(RM) $(OBJS)
		
fclean: clean
		$(RM) $(NAME)

re: fclean all