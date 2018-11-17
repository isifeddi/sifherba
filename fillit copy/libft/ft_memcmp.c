/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:50:01 by oherba            #+#    #+#             */
/*   Updated: 2018/10/07 17:32:24 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*p1;
	unsigned char		*o2;

	p1 = (unsigned char *)s1;
	o2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != o2[i])
			return (p1[i] - o2[i]);
		i++;
	}
	return (0);
}
