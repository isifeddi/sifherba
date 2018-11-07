/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:07:53 by oherba            #+#    #+#             */
/*   Updated: 2018/10/16 11:10:37 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*toto;

	if (alst)
	{
		while (*alst)
		{
			toto = (*alst)->next;
			ft_lstdelone(&*alst, del);
			*alst = toto;
		}
		*alst = NULL;
	}
}
