/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:57:43 by oherba            #+#    #+#             */
/*   Updated: 2018/10/08 21:17:13 by oherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int					i;
	unsigned char		*s11;
	unsigned char		*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s11[i] - s22[i]);
		i++;
	}
	return (s11[i] - s22[i]);
}
