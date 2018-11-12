/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:33:24 by oherba            #+#    #+#             */
/*   Updated: 2018/11/12 16:02:16 by oherba           ###   ########.fr       */
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
	ft_final_pos(tmp_pos);
	return (tmp_pos);
}

void	ft_final_pos(t_coor *pos)
{
	while (pos)
	{
		while (pos->tab[0].x && pos->tab[1].x && pos->tab[2].x && pos->tab[3].x)
		{
			pos->tab[0].x--;
			pos->tab[1].x--;
			pos->tab[2].x--;
			pos->tab[3].x--;
		}
		while (pos->tab[0].y && pos->tab[1].y && pos->tab[2].y && pos->tab[3].y)
		{
			pos->tab[0].y--;
			pos->tab[1].y--;
			pos->tab[2].y--;
			pos->tab[3].y--;
		}
		pos = pos->next;
	}
}
