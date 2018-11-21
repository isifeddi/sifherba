/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:30:55 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/21 17:31:02 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_initialise_zero(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * 20);
	while (i < 20)
	{
		str[i] = malloc(sizeof(char) * 20);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			if (str[i][j] != '#')
				str[i][j] = '0';
			j++;
		}
		i++;
	}
	return (str);
}

char	**ft_point(char **str, int x)
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
			if (str[i][j] == '0')
				str[i][j] = '.';
			j++;
		}
		i++;
	}
	return (str);
}

int		ft_c_arret(char **board, t_coor *lstpos, int y, int x)
{
	if (board[lstpos->tab[0].y + y][lstpos->tab[0].x + x] == '0' &&
			board[lstpos->tab[1].y + y][lstpos->tab[1].x + x] == '0' &&
			board[lstpos->tab[2].y + y][lstpos->tab[2].x + x] == '0' &&
			board[lstpos->tab[3].y + y][lstpos->tab[3].x + x] == '0')
		return (0);
	return (1);
}

void	ft_delete(char **board, char alpha)
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
