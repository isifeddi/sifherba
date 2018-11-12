/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isifeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:26:25 by isifeddi          #+#    #+#             */
/*   Updated: 2018/11/12 11:26:29 by isifeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid_line(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) != 4)
	{
		ft_putstr("one line is invalid");
		return (0);
	}
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.')
		{
			ft_putstr("one line is invalid");
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_read_void_line(const int fd, char *str)
{
	if (get_next_line(fd, &str) > 0 && str[0])
	{
		ft_putstr("error i l ya pas de line vide");
		return (0);
	}
	return (1);
}

int		ft_nbr_hash(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (str[i] == '#')
			j++;
		i++;
	}
	return (j);
}

int		ft_read_4_line(int *nd, const int fd, char *str, t_lst *tetri)
{
	int i;
	int j;
	int cpt;

	i = 0;
	j = 0;
	cpt = 0;
	while (i < 4 && ((*nd) = get_next_line(fd, &str)) > 0)
	{
		if (!ft_valid_line(str))
			return (0);
		j = j + ft_nbr_hash(str);
		tetri->tet[i] = ft_strdup(str);
		i++;
	}
	if ((*nd) == 0)
		return (1);
	if (j != 4)
		return (0);
	if (!ft_valid_tetri(tetri->tet, cpt))
		return (0);
	else
		return (1);
}

t_lst	*ft_read_file(const int fd)
{
	char	*str;
	int		nd;
	t_lst	*tmprr;
	t_lst	*tetri;

	nd = 1;
	tmprr = NULL;
	str = NULL;
	while (nd > 0)
	{
		tetri = ft_lst_new();
		if (!ft_read_4_line(&nd, fd, str, tetri))
			return (NULL);
		if (nd == 0)
			break ;
		if (!ft_read_void_line(fd, str))
			return (NULL);
		tmprr = ad_lst_addend(tmprr, tetri);
	}
	return (tmprr);
}
