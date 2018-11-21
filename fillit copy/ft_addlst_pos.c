/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlst_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:40:51 by oherba            #+#    #+#             */
/*   Updated: 2018/11/21 17:33:48 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coor	*ft_addlst_pos(t_coor *lst, t_coor *new)
{
	t_coor *tmp;

	tmp = lst;
	if (lst == NULL)
		return (new);
	tmp = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	new->prev = lst;
	return (tmp);
}
