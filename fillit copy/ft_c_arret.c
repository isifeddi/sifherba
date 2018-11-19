/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_arret.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:45:15 by oherba            #+#    #+#             */
/*   Updated: 2018/11/19 16:33:18 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_c_arret( (char **board, t_coor *lstpos,int *y ,int *x)
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
