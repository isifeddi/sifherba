/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 19:46:18 by oherba            #+#    #+#             */
/*   Updated: 2018/10/17 13:08:42 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *toto;
	t_list *head;

	if (!lst)
		return (0);
	toto = malloc(sizeof(t_list));
	if (!toto)
		return (NULL);
	toto = f(lst);
	head = toto;
	lst = lst->next;
	while (lst)
	{
		toto->next = f(ft_lstnew((lst)->content, (lst)->content_size));
		toto = toto->next;
		lst = lst->next;
	}
	return (head);
}
