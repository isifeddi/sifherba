/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:32:00 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/12 11:10:01 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_coor(t_lst *tetri, t_coor *lst_pos, t_coor *tmp_pos)
{
	int i;
	int j;
	int o;

	o = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetri->tet[i][j] == '#')
			{
				lst_pos->tab[o].x = j;
				lst_pos->tab[o].y = i;
				o++;
			}
		}
	}
	o = 0;
}

t_coor	*ft_hash_pos(t_lst *tetri)
{
	t_coor	*lst_pos;
	t_coor	*tmp_pos;
	int		o;
	int		i;
	int		j;

	tmp_pos = NULL;
	while (tetri)
	{
		lst_pos = ft_lstnew_coor();
		ft_coor(tetri, lst_pos, tmp_pos);
		tmp_pos = ft_addlst_pos(tmp_pos, lst_pos);
		tetri = tetri->next;
	}
	return (tmp_pos);
}
