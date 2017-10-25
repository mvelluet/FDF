/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:22:00 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/11 18:22:24 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	car;
	unsigned int	i;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	car = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*str1++ = *str2++) == car)
			return (str1);
		i++;
	}
	return (NULL);
}
