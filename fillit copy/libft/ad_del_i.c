/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 23:32:49 by oherba            #+#    #+#             */
/*   Updated: 2018/10/18 20:06:32 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ad_del_i(t_list **lst, int i)
{
	int		j;
	t_list	*tmprr;

	j = 0;
	tmprr = *lst;
	if (i == 1)
	{
		tmprr = (*lst)->next;
		free(*(lst));
		return (tmprr);
	}
	while ((*lst)->next)
	{
		j++;
		if (j + 1 == i)
		{
			(*lst)->next = ((*lst)->next)->next;
			free(*lst);
			if ((*lst)->next == NULL)
				return (tmprr);
		}
		lst = &(*lst)->next;
	}
	return (tmprr);
}
