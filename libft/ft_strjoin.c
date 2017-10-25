/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:40:50 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/13 11:00:58 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_d_len(char const *s1, char const *s2)
{
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	return (len1 + len2);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		j = 0;
		if (!(dst = (char *)malloc(sizeof(char *) * (ft_d_len(s1, s2)) + 1)))
			return (0);
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			dst[i] = s2[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}
