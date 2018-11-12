/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:11:18 by oherba            #+#    #+#             */
/*   Updated: 2018/11/12 21:51:44 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_point(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if(str[i][j] != '#')
				str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (str);
}
	


void	ft_place_tetri(t_coor *lstpos)
{
	char	**board;
	int i;
	int j;
	char alpha;

	j = 0;
	i = 0;
	alpha = 'A';
	board = malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		board[i]  = malloc(sizeof(char) * 4);
		i++;
	}
	ft_point(board);
//	i = 0;

//	while(lstpos)
//	{
		board[lstpos->tab[0].y][lstpos->tab[0].x] = alpha;
		board[lstpos->tab[1].y][lstpos->tab[1].x] = alpha;
		board[lstpos->tab[2].y][lstpos->tab[2].x] = alpha;
		board[lstpos->tab[3].y][lstpos->tab[3].x] = alpha;
		while (j < 4)
		{
			ft_putstr("\n");
			ft_putstr(board[j]);
			j++;
		}

	//}
}
