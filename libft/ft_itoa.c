/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:40:50 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/13 10:58:52 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strlen_itoa(int n)
{
	int		temp;
	int		i;

	i = 0;
	if (n <= 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 0)
	{
		temp = n % 10;
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		imax;
	int		ntemp;
	int		temp;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ntemp = n;
	imax = ft_strlen_itoa(n);
	if (!(s = (char *)malloc(sizeof(*s) * (imax) + 1)))
		return (0);
	if (n < 0)
		ntemp = n * (-1);
	if (n < 0)
		s[0] = '-';
	s[imax] = '\0';
	while (ntemp > 0)
	{
		temp = ntemp % 10;
		s[(imax--) - 1] = temp + '0';
		ntemp = ntemp / 10;
	}
	return (s);
}
