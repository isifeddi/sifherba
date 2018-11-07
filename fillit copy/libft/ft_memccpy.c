/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 22:21:10 by oherba            #+#    #+#             */
/*   Updated: 2018/10/12 11:35:24 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	unsigned char		*str;
	unsigned char		o;

	ptr = (unsigned char *)dst;
	str = (unsigned char *)src;
	i = 0;
	o = (unsigned char)c;
	while (i < n)
	{
		ptr[i] = str[i];
		if (str[i] == o)
			return (ptr + i + 1);
		i++;
	}
	return (NULL);
}
