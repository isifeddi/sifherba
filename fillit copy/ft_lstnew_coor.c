/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_coor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:27:41 by oherba            #+#    #+#             */
/*   Updated: 2018/11/12 11:11:39 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coor	*ft_lstnew_coor(void)
{
	t_coor	*new;

	if ((new = malloc(sizeof(t_coor))) == NULL)
		return (NULL);
	new->next = NULL;
	return (new);
}
