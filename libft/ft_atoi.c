/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:32:47 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/14 02:33:59 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int number;
	int negatif;

	i = 0;
	number = 0;
	negatif = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45)
		negatif = 1;
	if ((str[i] == 43) || (str[i] == 45))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10;
		number = number + ((int)str[i] - 48);
		i++;
	}
	if (negatif == 1)
		return (-number);
	else
		return (number);
}
