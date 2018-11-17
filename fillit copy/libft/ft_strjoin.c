/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:39:06 by oherba            #+#    #+#             */
/*   Updated: 2018/10/13 11:59:32 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (s2 == NULL || s1 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)ft_memalloc(sizeof(char) * (i + 1))) == NULL)
		return (0);
	str = ft_strcat(str, (char *)s1);
	str = ft_strcat(str, (char *)s2);
	str[i + 1] = '\0';
	return (str);
}
