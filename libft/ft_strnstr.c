/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:44:42 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/13 10:42:06 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litl, size_t len)
{
	size_t	lenght;

	if (*litl == '\0')
		return ((char *)big);
	lenght = ft_strlen(litl);
	while (*big != '\0' && len >= lenght)
	{
		if (*big == *litl && ft_memcmp(big, litl, lenght) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
