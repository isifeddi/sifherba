/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:10:55 by oherba            #+#    #+#             */
/*   Updated: 2018/10/13 15:34:54 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (s == NULL)
		return (NULL);
	if (!*s)
		return (0);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	ft_strncpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
