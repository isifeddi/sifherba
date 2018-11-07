/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:20:32 by oherba            #+#    #+#             */
/*   Updated: 2018/11/07 22:31:26 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_lst(t_lst *lst)
{
	while (lst)
	{
		ft_putstr(lst->tet[0]);
		ft_putstr("\n");
		ft_putstr(lst->tet[1]);
		ft_putstr("\n");
		ft_putstr(lst->tet[2]);
		ft_putstr("\n");
		ft_putstr(lst->tet[3]);
		ft_putstr("\n");
		lst = lst->next;
	}
}