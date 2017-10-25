/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:54:14 by mvelluet          #+#    #+#             */
/*   Updated: 2017/01/10 22:56:34 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = ft_strlen(s1);
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	dest[i] = '\0';
	i--;
	while (i >= 0)
	{
		dest[i] = s1[i];
		i--;
	}
	return (dest);
}
