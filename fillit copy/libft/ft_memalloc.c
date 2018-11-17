/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 09:44:18 by oherba            #+#    #+#             */
/*   Updated: 2018/10/10 21:35:00 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	str = (void *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, size);
	return ((void *)str);
}
