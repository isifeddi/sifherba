#ifndef FILLIT_H

# define FILLIT_H

# include "get_next_line.h"

typedef	struct		s_lst
{
	char			**tet;
	struct s_lst	*next;
}					t_lst;

int					ft_valid_line(char *str);
int					ft_valid_nbr_line(const int fd);
t_lst				*ft_read_file (const int fd);
t_lst				*ft_lst_new();
void				ft_print_lst(t_lst *lst);
t_lst				*ad_lst_addend(t_lst *lst, t_lst *new);
int					ft_valid_tetri(char **str, int cpt);
int					ft_srsh(char **str, int i, int j);
int					**ft_hash_pos(char **str);

typedef struct      s_point
{
	int				x;
	int             y;
}					t_point;

typedef struct		s_coor
{
	t_point		tab[4];
	struct s_coor	*next;
}					t_coor;

#endif
