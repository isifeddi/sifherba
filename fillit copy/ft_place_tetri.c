/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:11:18 by oherba            #+#    #+#             */
/*   Updated: 2018/11/20 23:35:45 by oherba           ###   ########.fr       */
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
	if (board[lstpos->tab[0].y + y ][lstpos->tab[0].x + x] == '0' &&
			board[lstpos->tab[1].y + y][lstpos->tab[1].x + x ] == '0' &&
			board[lstpos->tab[2].y + y ][lstpos->tab[2].x + x ] == '0' &&
			board[lstpos->tab[3].y + y ][lstpos->tab[3].x + x ] == '0')
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

void    ft_delete(char **board, char alpha)
{
	int i;
	int j;

	i = 0;
	while (i != 20)
	{
		j = 0;
		while (j != 20)
		{
			if (board[i][j] == alpha)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_search(char **board,char alpha,int *x,int *y)
{
	while (board[*y][*x]!='0')
	{
		while(board[*y][*x]!='0')
		{
			if(board[*y][*x]==alpha)
				break;
			(*x)++;
		}
		if(board[*y][*x]==alpha)
			break;
		(*x) = 0;
		(*y)++;
	}
	if(board[*y][(*x)+1]=='0')
	{
		*x=-1;
		(*y)++;
	}
}

int		check_place(char **board, t_coor *lstpos, char alpha,int mode)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 0;
	if(mode==1)
	{
		ft_search(board,alpha,&x ,&y);
		ft_delete(board,alpha);
		x+=-(lstpos->tab[0].x-1);
	}
	if (ft_find_x_y(board,lstpos,&y ,&x))
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

void	ft_print_res(char **board, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putstr_zero(board[j]);
		ft_putstr("\n");
		j++;
	}
}

void	ft_else(int *mode, char *alpha, t_coor *lstpos)
{
	(*mode) = 1;
	if((*alpha) !='A')
	{
		(*alpha)--;
		lstpos = lstpos->prev;
	}
}
void	ft_place(t_coor *lstpos)
{
	char alpha;
	int i;
	char   **board;
	int		mode;

	i = 2;
	alpha = 'A';
	board = ft_initialise_zero(board);
	ft_point(board, i);
	mode = 0;
	while(lstpos)
	{
		if (check_place(board,lstpos,alpha,mode) == 1)
		{
			mode=0;
			alpha++;
			lstpos = lstpos->next;
		}
		else if (alpha == 'A')
		{
			mode = 0;
			i++;
			ft_point(board,i);
		}
		else
			ft_else(&mode, &alpha, lstpos);
	}
	ft_print_res(board, i);
}
