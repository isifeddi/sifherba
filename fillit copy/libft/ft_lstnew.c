/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:00:12 by oherba            #+#    #+#             */
/*   Updated: 2018/10/15 13:08:01 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = malloc(sizeof(*fresh));
	if (fresh == NULL)
		return (NULL);
	fresh->content = malloc(sizeof(fresh->content) * content_size);
	if (fresh->content == NULL)
		return (NULL);
	fresh->next = NULL;
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
		return (fresh);
	}
	ft_memcpy(fresh->content, content, content_size);
	fresh->content_size = content_size;
	return (fresh);
}
