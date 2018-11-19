/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:20:32 by oherba            #+#    #+#             */
/*   Updated: 2018/11/19 12:40:35 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*ad_lst_addend(t_lst *lst, t_lst *new)
{
	t_lst	*tmprr;

	if (lst == NULL)
		return (new);
	tmprr = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	return (tmprr);
}
