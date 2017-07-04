# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/14 15:23:53 by vkannema          #+#    #+#              #
#    Updated: 2017/04/26 11:21:12 by vkannema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
C_DIR = srcs
O_DIR = objects
INCLUDES = -I ./includes -I ./Libft/includes
LIB = -L./Libft/ -lftprintf
C_FILES = srcs/free_list.c \
	srcs/init_graph.c \
	srcs/parse.c \
	srcs/ft_list.c \
	srcs/main.c \
	srcs/parse_edge.c \
	srcs/parse_room_helper.c \
	srcs/errors.c \
	srcs/get_path.c \
	srcs/move_ants.c \
	srcs/parse_edge_helper.c

O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)
FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME): $(O_FILES)
	make -C Libft
	@gcc $(FLAGS) $(LIB) $(O_FILES) -o $(NAME)
	@printf "\033[0;33m Lem-in FINISHED !\033[0;0m\n"

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIR)
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $< \
	 && printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<"

clean :
	@rm -rf $(O_DIR)
	@make clean -C ./Libft
	@echo "Objects cleaned"

fclean : clean
	@make fclean -C ./Libft
	@rm -f $(NAME)
	@echo "Deleted exec"

re : fclean all
