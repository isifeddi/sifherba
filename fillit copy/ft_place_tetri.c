/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:11:18 by oherba            #+#    #+#             */
/*   Updated: 2018/11/15 21:23:35 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_initialise_zero(char **str)
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
				str[i][j] = '0';
			j++;
		}
		i++;
	}
	return (str);
}
char **ft_point(char **str, int x)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < x)
	{
		j = 0;
		while (j < x)
		{
			if(str[i][j] == '0')
				str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (str);
}

void	ft_place_one_tetri(t_coor *lstpos, int y, int x, char  **board, char alpha)
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

int		check_place(char **board, t_coor *lstpos, int y, int x)
{
	while (board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] != '.' || board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] != '.' ||board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] != '.' || board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] != '.')
	{
		x++;
		if (x == 2)
		{
			x = 0;
			y++;
		}
	}
	if ((board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] == '.') && (board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] == '.') && (board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] == '.') && (board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] == '.'))
		return (1);
	else 
		return (0);
}

char 	**ft_alloc(char **board)
{
	int i;

	i = 0;
   	board = malloc(sizeof(char *) * 20);
   	while (i < 20)
	{
		      board[i]  = malloc(sizeof(char) * 20);
		        i++;
	}
	return (board);
}

void	ft_print_res(char **board, int i)
{
	int j;

	j = 0;
	while (j < i)
	    {
		         ft_putstr("\n");
		         ft_putstr_zero(board[j]);
		         j++;
		 }
}

void	ft_place(t_coor *lstpos)
{
	int x;
	int y;
	char alpha;
	int i;
	char    **board;

	x = 0;
	y = 0;
	i = 3;
	alpha = 'A';
    board =	ft_alloc(board);
	ft_initialise_zero(board);
	ft_point(board, i);
	while(lstpos)
	{
		if (check_place(board,lstpos, y, x) == 1)
		{
			ft_place_one_tetri(lstpos,y,x,board, alpha);
			alpha++;
			lstpos = lstpos->next;
		}
		else
		{
			i++;
			ft_point(board,i);
		}
	}
	ft_print_res(board, i);
}
