/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:41:26 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/14 02:17:54 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int length;

	length = 0;
	i = ft_strlen(dest);
	while (src[length] && length < nb)
	{
		dest[i] = src[length];
		length++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
