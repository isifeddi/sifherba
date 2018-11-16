/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:11:18 by oherba            #+#    #+#             */
/*   Updated: 2018/11/16 15:24:29 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_initialise_zero(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * 20);
	while (i < 20)
	{
		str[i]  = malloc(sizeof(char) * 20);
		i++;
	}
	i = 0;
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
	board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] = alpha;
	board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] = alpha;
	board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] = alpha;
	board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] = alpha;
}
/*int 	ft_find_x_y(char **board, t_coor *lstpos,int *y ,int *x)
{
	while (board[lstpos->tab[0].y + *y][lstpos->tab[0].x + *x] != '.' || board[lstpos->tab[1].y + *y][lstpos->tab[1].x + *x] != '.' ||board[lstpos->tab[2].y + *y][lstpos->tab[2].x + *x] != '.' || board[lstpos->tab[3].y + *y][lstpos->tab[3].x + *x] != '.')
		    {
			          x++;
			         if (board[lstpos->tab[0].y + *y][lstpos->tab[0].x + *x] != '0' || board[lstpos->tab[1].y + *y][lstpos->tab[1].x + *x] != '0' ||board[lstpos->tab[2].y + *y][lstpos->tab[2].x + *x] != '0' || board[lstpos->tab[3].y + *y][lstpos->tab[3].x + *x] != '0')
				          {
						             x = 0;
						              y++;
						          }
			       }
	     if ((board[lstpos->tab[0].y + *y][lstpos->tab[0].x + *x] == '.') && (board[lstpos->tab[1].y + *y][lstpos->tab[1].x + *x] == '.') && (board[lstpos->tab[2].y + *y][lstpos->tab[2].x + *x] == '.') && (board[lstpos->tab[3].y + *y][lstpos->tab[3].x + *x] == '.'))
			            return (1);
	      else
		          return (0);
}*/

int		check_place(char **board, t_coor *lstpos, char alpha)
{
	int x;
	int y;

	x = 0;
	y = 0;
while (board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] != '.' || board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] != '.' ||board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] != '.' || board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] != '.')
	{
		x++;
		if (board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] != '0' || board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] != '0' ||board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] != '0' || board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] != '0')
		{
			x = 0;
			y++;
		}
	}
	if ((board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] == '.') && (board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] == '.') && (board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] == '.') && (board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] == '.'))
	{
					board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] = alpha;
				      board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] = alpha;
				      board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] = alpha;
				        board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] = alpha;

				return (1);
			}
			else 
				return (0);
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
	char alpha;
	int i;
	char    **board;

	i = 3;
	alpha = 'A';
	board = ft_initialise_zero(board);
	ft_point(board, i);
	while(lstpos)
	{
		if (check_place(board,lstpos,alpha) == 1)
		{
			//	ft_place_one_tetri(lstpos,y,x,board, alpha);
			alpha++;
			lstpos = lstpos->next;
		}
		else
		{
			i++;
			ft_point(board,10);
		}
	}
	ft_print_res(board, i);
}
