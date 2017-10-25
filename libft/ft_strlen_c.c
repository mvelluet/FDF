/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 00:58:14 by mvelluet          #+#    #+#             */
/*   Updated: 2017/01/12 21:46:00 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_c(char *str, char c)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == c)
			y++;
		i++;
	}
	i = 0;
	if (str && y > 0)
	{
		while (str[i] != c)
			i++;
		if (str[i] == c)
			i++;
		return (i);
	}
	i = ft_strlen(str);
	return (i);
}
