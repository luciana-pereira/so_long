# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 03:48:00 by lucperei          #+#    #+#              #
#    Updated: 2023/02/06 01:57:40 by lucperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -g3
RM = rm -rf
FLAGS = -Wall -Werror -Wextra -I./ -c
MLX_FLAGS = -lX11 -lXext -lmlx

SRC = srcs/so_long.c \
	srcs/moving.c \
	srcs/verify_map.c \
	srcs/map.c \
	srcs/create_map.c \
	srcs/key_input.c \
	srcs/end_game.c \

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

HEADER = srcs/so_long.h

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	$(CC) $(SRC) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	
clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re:	  fclean all 

run:	
	./$(NAME) maps/map.ber 
	
.PHONY: all clean fclean re  run 