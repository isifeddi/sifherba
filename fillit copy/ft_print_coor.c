/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:40:38 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/12 11:25:33 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_coor(t_coor *lst)
{
	int i;

	while (lst)
	{
		i = -1;
		while (++i < 4)
		{
			ft_putstr("\n");
			ft_putnbr(lst->tab[i].y);
			ft_putstr("\t");
			ft_putnbr(lst->tab[i].x);
			ft_putstr("\n");
		}
		ft_putstr("**********");
		lst = lst->next;
	}
}
