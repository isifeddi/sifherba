/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:08:50 by oherba            #+#    #+#             */
/*   Updated: 2018/10/30 20:49:35 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				i;
	int				fd_read;
	static char		*str[256];
	char			buf[BUFF_SIZE + 1];

	i = 0;
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while ((fd_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[fd_read] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	*line = ft_strsub(str[fd], 0, i);
	if (!fd_read && !ft_strlen(str[fd]))
		return (0);
	str[fd] = (ft_strchr(str[fd], str[fd][i]) + 1);
	return (1);
}
