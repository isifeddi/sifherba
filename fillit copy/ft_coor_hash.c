/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coor_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:19:06 by oherba            #+#    #+#             */
/*   Updated: 2018/11/10 17:42:13 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coor	*ft_coor_hash(t_lst *tetri)
{
	t_coor	*new;
	t_coor  *tmpnew;
	t_lst *tmptetri;
	int **tab;
	int **gta;
	int i;
	const int fd;

	i = 0;
	tetri = ft_read_file(fd);
	tmpnew = new;
	tmptetri = tetri;
	tab = malloc(sizeof(int *) * 4);
	gta = malloc(sizeof(int *) * 4);
	ft_lstnew_coor();
	ft_new_lst();
	gta = ft_hash_pos(tetri->tet);
	while (tmpnew->next != NULL && tmptetri->next != NULL)
	{
		i = 0;
		while (i++ < 4)
		{
			tmpnew->tab[i].y = gta[i][0];
			tmpnew->tab[i].x = gta[i][1];
		}
		tmpnew = tmpnew->next;
		tmptetri = tetri->next;
	}
	return (new);
}
