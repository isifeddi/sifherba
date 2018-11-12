/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_nbr_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:25:39 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/12 11:25:45 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_valid_nbr_line(const int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (get_next_line(fd, &str) > 0)
	{
		i++;
	}
	ft_putstr("nbr isssss");
	ft_putnbr(i);
	ft_putstr("\n");
	if (i % 5)
	{
		ft_putstr("error");
		return (0);
	}
	ft_putstr("good nbr line\n");
	return (1);
}
