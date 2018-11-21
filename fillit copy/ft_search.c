/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:24:23 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/21 17:29:20 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_search(char **board, char alpha, int *x, int *y)
{
	while (board[*y][*x] != '0')
	{
		while (board[*y][*x] != '0')
		{
			if (board[*y][*x] == alpha)
				break ;
			(*x)++;
		}
		if (board[*y][*x] == alpha)
			break ;
		(*x) = 0;
		(*y)++;
	}
	if (board[*y][(*x) + 1] == '0')
	{
		*x = -1;
		(*y)++;
	}
}
