/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:02:51 by oherba            #+#    #+#             */
/*   Updated: 2018/11/21 17:58:10 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_zero(char const *s)
{
	if (s)
	{
		while (*s != '0')
		{
			ft_putchar(*s);
			s++;
		}
	}
}
