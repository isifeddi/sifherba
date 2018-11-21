/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:37:16 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/21 17:38:49 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_lst	*toto;
	t_coor	*lolo;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		toto = ft_read_file(fd);
		if (!toto)
		{
			ft_putendl("error");
			return (0);
		}
		lolo = ft_hash_pos(toto);
		ft_place(lolo);
	}
	else
		ft_putstr("usage");
	return (0);
}
