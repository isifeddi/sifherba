/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 18:22:13 by oherba            #+#    #+#             */
/*   Updated: 2018/10/30 19:41:40 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <sys/stat.h>

# include <fcntl.h>

# include <unistd.h>

# include "libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
