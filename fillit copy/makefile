# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 17:40:17 by isifeddi          #+#    #+#              #
#    Updated: 2018/11/21 17:44:23 by isifeddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft/libft.a
SRC = ft_addlst_pos.c ft_hash_pos.c ft_lst_addend.c ft_lstnew_coor.c ft_new_lst.c ft_place_tetri.c ft_putstr_zero.c ft_read_file.c ft_relat.c ft_search.c get_next_line.c main.c solve_tools.c
OBJ = ft_addlst_pos.o ft_hash_pos.o ft_lst_addend.o ft_lstnew_coor.o ft_new_lst.o ft_place_tetri.o ft_putstr_zero.o ft_read_file.o ft_relat.o ft_search.o get_next_line.o main.o solve_tools.o
all : $(NAME)
$(NAME) :
	gcc -c $(SRC) -Wall -Wextra -Werror
	ar rc $(NAME) $(OBJ)
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all
