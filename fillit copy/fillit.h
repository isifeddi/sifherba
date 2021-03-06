/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:14:26 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/21 17:32:23 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "get_next_line.h"

typedef	struct		s_lst
{
	char			**tet;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_coor
{
	t_point			tab[4];
	struct s_coor	*next;
	struct s_coor	*prev;
}					t_coor;

int					ft_valid_line(char *str);
t_lst				*ft_read_file (const int fd);
t_lst				*ft_lst_new();
t_lst				*ad_lst_addend(t_lst *lst, t_lst *new);
int					ft_valid_tetri(char **str, int cpt);
t_coor				*ft_lstnew_coor(void);
t_coor				*ft_addlst_pos(t_coor *lst, t_coor *new);
t_coor				*ft_hash_pos(t_lst *tetri);
void				ft_final_pos(t_coor *pos);
char				**ft_initialise_zero(char **str);
void				ft_place_one_tetri(t_coor *lstpos,
		int y, int x, char **board, char alpha);
void				ft_place(t_coor *lstpos);
void				ft_putstr_zero(char const *s);
void				ft_print_res(char **board, int i);
char				**ft_point(char **str, int x);
int					ft_c_arret(char **board, t_coor *lstpos, int y, int x);
void				ft_delete(char **board, char alpha);
void				ft_print_res(char **board, int i);
void				ft_search(char **board, char alpha, int *x, int *y);

#endif
