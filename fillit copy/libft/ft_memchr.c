/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:01:23 by oherba            #+#    #+#             */
/*   Updated: 2018/10/07 20:30:38 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*r;
	char		l;

	l = c;
	r = (char *)s;
	i = 0;
	while (i < n)
	{
		if (*r == l)
			return ((void *)r);
		i++;
		r++;
	}
	return (0);
}
