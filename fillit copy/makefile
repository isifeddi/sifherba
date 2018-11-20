# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oherba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 22:33:57 by oherba            #+#    #+#              #
#    Updated: 2018/11/20 22:52:49 by oherba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft/libft.a
SRC = ad_lst_addend.c ft_addlst_pos.c ft_hash_pos.c ft_lstnew_coor.c ft_new_lst.c ft_place_tetri.c ft_print_coor.c ft_print_lst.c ft_putstr_zero.c ft_read_file.c ft_relat.c ft_valid_nbr_line.c get_next_line.c main.c
OBJ = ad_lst_addend.o ft_addlst_pos.o ft_hash_pos.o ft_lstnew_coor.o ft_new_lst.o ft_place_tetri.o ft_print_coor.o ft_print_lst.o ft_putstr_zero.o ft_read_file.o ft_relat.o ft_valid_nbr_line.o get_next_line.o main.o

all : $(NAME)
$(NAME) :
	gcc -c $(SRC) -Wall -Wextra -Werror
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all
