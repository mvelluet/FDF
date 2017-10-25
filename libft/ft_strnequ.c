/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:40:50 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/11 18:43:52 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	if (s1 != NULL && s2 != NULL)
	{
		i = ft_strncmp(s1, s2, n);
		if (i == 0)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
