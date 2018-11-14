/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:11:18 by oherba            #+#    #+#             */
/*   Updated: 2018/11/14 15:32:30 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_point(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			if(str[i][j] != '#')
				str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (str);
}



void	ft_place_one_tetri(t_coor *lstpos, int y, int x, char    **board, char alpha)
{
	int i;
	int j;

	j = 0;
	i = 0;
	board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] = alpha;
	board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] = alpha;
	board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] = alpha;
	board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] = alpha;
}

void	ft_place(t_coor *lstpos)
{
	int x;
	int y;
	 char alpha;
	int i;
	int j;
	char    **board;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	alpha = 'A';
	board = malloc(sizeof(char *) * 20);
	while (i < 20)
	{
		board[i]  = malloc(sizeof(char) * 20);
		i++;
	}
	ft_point(board);
	while(lstpos)
	{
		while (board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] != '.' || board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] != '.' ||
		board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] != '.' || board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] != '.')
		{
			x++;
			if (x == 20)
			{
				x = 0;
				y++;
			}
		}
		ft_place_one_tetri(lstpos,y,x,board, alpha);
		lstpos = lstpos->next;
		alpha++;
	}

	while (j < 20)
	{
		ft_putstr("\n");
		ft_putstr(board[j]);
		j++;
	}
}
