/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:52:42 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/12 00:52:55 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	if (len == 0 || dst == src)
		return (dst);
	if (dst < src)
	{
		while (len-- > 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	if (dst > src)
	{
		while (len--)
			s1[len] = s2[len];
	}
	return (dst);
}
