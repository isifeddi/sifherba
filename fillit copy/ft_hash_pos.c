/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:32:00 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/11 22:09:13 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coor	*ft_hash_pos(t_lst *tetri)
{
	int o;
	int i;
	int j;
	t_coor	*lst_pos;
	t_coor	*tmp_pos;

	o = 0;
	i = -1;
	tmp_pos = NULL;
	while(tetri)
	{
		i = -1;
		ft_putnbr(1);
		ft_putchar('\n');
		lst_pos = ft_lstnew_coor();
		while (++i < 4)
		{
	
			j = -1;
			while (++j < 4)
			{
				if (tetri->tet[i][j] == '#')
				{
					lst_pos->tab[o].x = i;
					lst_pos->tab[o].y = j;
					o++;
				}
			}
		}
		tmp_pos = ft_addlst_pos(tmp_pos, lst_pos);
		tetri = tetri->next;
		o = 0;
	}
	return (tmp_pos);
}
