/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:11:18 by oherba            #+#    #+#             */
/*   Updated: 2018/11/21 18:01:44 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_x_y(char **board, t_coor *lstpos, int *y, int *x)
{
	while (board[lstpos->tab[0].y + *y][lstpos->tab[0].x + *x] != '.' ||
			board[lstpos->tab[1].y + *y][lstpos->tab[1].x + *x] != '.' ||
			board[lstpos->tab[2].y + *y][lstpos->tab[2].x + *x] != '.' ||
			board[lstpos->tab[3].y + *y][lstpos->tab[3].x + *x] != '.')
	{
		if (!ft_c_arret(board, lstpos, *y, *x))
			break ;
		(*x)++;
		if (board[lstpos->tab[0].y + *y][lstpos->tab[0].x + *x] == '0' ||
				board[lstpos->tab[1].y + *y][lstpos->tab[1].x + *x] == '0' ||
				board[lstpos->tab[2].y + *y][lstpos->tab[2].x + *x] == '0' ||
				board[lstpos->tab[3].y + *y][lstpos->tab[3].x + *x] == '0')
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

int		check_place(char **board, t_coor *lstpos, char alpha, int mode)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 0;
	if (mode == 1)
	{
		ft_search(board, alpha, &x, &y);
		ft_delete(board, alpha);
		x += -(lstpos->tab[0].x - 1);
	}
	if (ft_find_x_y(board, lstpos, &y, &x))
	{
		while (i < 4)
		{
			board[lstpos->tab[i].y + y][lstpos->tab[i].x + x] = alpha;
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_else(int *mode, char *alpha, t_coor **lstpos)
{
	(*mode) = 1;
	if ((*alpha) != 'A')
	{
		(*alpha)--;
		(*lstpos) = (*lstpos)->prev;
	}
}

void	ft_else_if(int *i, int *mode, char ***board)
{
	(*mode) = 0;
	(*i)++;
	ft_point((*board), (*i));
}

void	ft_place(t_coor *lstpos)
{
	char	alpha;
	int		i;
	char	**board;
	int		mode;

	board = NULL;
	i = 2;
	alpha = 'A';
	board = ft_initialise_zero(board);
	ft_point(board, i);
	mode = 0;
	while (lstpos)
	{
		if (check_place(board, lstpos, alpha, mode) == 1)
		{
			mode = 0;
			alpha++;
			lstpos = lstpos->next;
		}
		else if (alpha == 'A')
			ft_else_if(&i, &mode, &board);
		else
			ft_else(&mode, &alpha, &lstpos);
	}
	ft_print_res(board, i);
}
