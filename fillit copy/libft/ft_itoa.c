/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:57:28 by oherba            #+#    #+#             */
/*   Updated: 2018/10/19 12:42:53 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		f_len_int(int n)
{
	int ctr;

	ctr = 1;
	while (n / 10 != 0)
	{
		ctr++;
		n = n / 10;
	}
	return (ctr);
}

static char		*f_i_n(int n)
{
	char	*str;
	int		i;

	i = f_len_int(n);
	if ((str = (char *)malloc(sizeof(char) * (i + 2))) == NULL)
		return (NULL);
	str[i + 1] = '\0';
	str[0] = '-';
	while (n != 0)
	{
		str[i] = -(n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

static char		*f_i_p(int n)
{
	char	*str;
	int		i;

	i = f_len_int(n) - 1;
	if ((str = (char *)malloc(sizeof(char) * (i + 1 + 1))) == NULL)
		return (NULL);
	str[i + 1] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;

	str = (n >= 0) ? f_i_p(n) : f_i_n(n);
	return (str);
}
