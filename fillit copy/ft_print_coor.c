/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_coor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:40:38 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/11 22:06:49 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_print_coor(t_coor *lst)
{
	while (lst)
	{
		ft_putstr("\n");
		ft_putnbr(lst->tab[0].y);
		ft_putstr("\t");
		ft_putnbr(lst->tab[0].x);
		ft_putstr("\n");
		ft_putnbr(lst->tab[1].y);
		ft_putstr("\t");
		ft_putnbr(lst->tab[1].x);
		ft_putstr("\n");
		ft_putnbr(lst->tab[2].y);
		ft_putstr("\t");
		ft_putnbr(lst->tab[2].x);
		ft_putstr("\n");
		ft_putnbr(lst->tab[3].y);
		ft_putstr("\t");
		ft_putnbr(lst->tab[3].x);
		ft_putstr("\n");
		ft_putstr("************");
		lst = lst->next;
	}
}
