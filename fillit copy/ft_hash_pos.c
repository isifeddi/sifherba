/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:32:00 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/10 13:49:15 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int  **ft_hash_pos(char **str)
{
	int o;
	int i;
	int j;
	int **gta;

	o = 0;
	i = -1;
	gta = malloc(sizeof(int *) * 4);
	gta[0] = malloc(sizeof(int) * 2);
	gta[1] = malloc(sizeof(int) * 2);
	gta[2] = malloc(sizeof(int) * 2);
	gta[3] = malloc(sizeof(int) * 2);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (str[i][j] == '#')
			{
				gta[o][0] = i;
				gta[o][1] = j;
				o++;
			}
		}
	}
	return (gta);
}
