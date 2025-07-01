# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 10:50:22 by ajurczyk          #+#    #+#              #
#    Updated: 2025/07/01 14:11:00 by ajurczyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wextra -Wall -Werror
MLXPATH = minilibx-linux
MLXLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11 
SRCS = $(addsuffix .c, so_long set_utils game_utils move_utils libft_utils errors get_next_line)
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(MLXPATH)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXLAGS) -o $(NAME)
	
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

re: fclean all

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)