/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 00:24:40 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/16 00:43:55 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, int c)
{
	char	*dst;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
	len = ft_strlen((char *)s);
	while (s[len - 1] == c)
		len--;
	while (s[i] == c)
	{
		len--;
		i++;
	}
	if (len <= 0)
		len = 0;
	if (!(dst = (char *)malloc(sizeof(*s) * len + 1)))
		return (0);
	while (len-- != 0)
		dst[j++] = s[i++];
	dst[j] = '\0';
	return (dst);
}
