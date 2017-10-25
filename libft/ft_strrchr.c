/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:45:15 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/11 18:45:22 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int i;

	i = 0;
	i = ft_strlen(str);
	while (i != 0)
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
		i--;
	}
	if (str[i] == c)
	{
		return (&str[i]);
	}
	return (0);
}
