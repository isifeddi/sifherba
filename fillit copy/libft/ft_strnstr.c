/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:37:07 by oherba            #+#    #+#             */
/*   Updated: 2018/10/12 17:01:58 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && needle[i] && (i + j) < len)
		{
			i++;
		}
		if (needle[i] == '\0')
		{
			return ((char *)&haystack[j]);
			break ;
		}
		else
			j++;
	}
	return (0);
}
