/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:11:18 by oherba            #+#    #+#             */
/*   Updated: 2018/11/16 19:10:20 by oherba           ###   ########.fr       */
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

void	ft_remove_one_tetri(t_coor *lstpos, int y, int x, char  **board)
{
	int i;

	i = 0;
	while(i < 4)
	{	
		board[lstpos->tab[i].y + y][lstpos->tab[i].x + x] = '.';
		i++;
	}
}
int     ft_c_arret(char **board, t_coor *lstpos,int y ,int x)
{
	if (board[lstpos->tab[0].y + y + 1][lstpos->tab[0].x + x + 1] == '0' ||
			board[lstpos->tab[1].y + y + 1][lstpos->tab[1].x + x + 1] == '0' ||
			board[lstpos->tab[2].y + y + 1][lstpos->tab[2].x + x + 1] == '0' ||
			board[lstpos->tab[3].y + y + 1][lstpos->tab[3].x + x + 1] == '0')
	{
		return(0);
	}
	return (1);
}
int 	ft_find_x_y(char **board, t_coor *lstpos,int *y ,int *x)
{
	while (board[lstpos->tab[0].y + *y][lstpos->tab[0].x + *x] != '.' ||
			board[lstpos->tab[1].y + *y][lstpos->tab[1].x + *x] != '.' ||
			board[lstpos->tab[2].y + *y][lstpos->tab[2].x + *x] != '.' ||
			board[lstpos->tab[3].y + *y][lstpos->tab[3].x + *x] != '.')
	{
		if(!ft_c_arret(board,lstpos, *y ,*x))
			break ;
		(*x)++;
		if (board[lstpos->tab[0].y + *y][lstpos->tab[0].x + *x] != '0' ||
				board[lstpos->tab[1].y + *y][lstpos->tab[1].x + *x] != '0' ||
				board[lstpos->tab[2].y + *y][lstpos->tab[2].x + *x] != '0' ||
				board[lstpos->tab[3].y + *y][lstpos->tab[3].x + *x] != '0')
		{
			(*x) = 0;
			(*y)++;
		}
	}
	if ((board[lstpos->tab[0].y + *y][lstpos->tab[0].x + *x] == '.') && 
			(board[lstpos->tab[1].y + *y][lstpos->tab[1].x + *x] == '.') &&
			(board[lstpos->tab[2].y + *y][lstpos->tab[2].x + *x] == '.') && 
			(board[lstpos->tab[3].y + *y][lstpos->tab[3].x + *x] == '.'))
		return (1);
	else
		return (0);
}

int		check_place(char **board, t_coor *lstpos, char alpha)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 0;
	if (ft_find_x_y(board,lstpos,&y ,&x))
	{
		while (i < 4)
		{	
			board[lstpos->tab[i].y + y][lstpos->tab[i].x + x] = alpha;
			i++;
		}
		ft_print_res(board, 0);
		ft_putstr("\n\n\n");
		return (1);
	}
	else 
		return (0);
}

void	ft_print_res(char **board, int i)
{
	int j;

	j = 0;
	i = 0;
	while (j < 10)
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

	i = 2;
	alpha = 'A';
	board = ft_initialise_zero(board);
	ft_point(board, i);
	while(lstpos)
	{
		if (check_place(board,lstpos,alpha) == 1)
		{
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
