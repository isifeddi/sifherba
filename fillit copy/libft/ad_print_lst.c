/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:20:32 by oherba            #+#    #+#             */
/*   Updated: 2018/10/18 20:10:52 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ad_print_lst(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		ft_putstr("           ");
		ft_putnbr(lst->content_size);
		ft_putchar('\n');
		lst = lst->next;
	}
}
