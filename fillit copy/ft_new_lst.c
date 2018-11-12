/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:14:58 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/12 11:15:00 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	*ft_lst_new(void)
{
	t_lst	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->tet = malloc(sizeof(char *) * 4);
	new->next = NULL;
	return (new);
}
