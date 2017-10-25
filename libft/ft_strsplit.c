/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:25:07 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/14 02:31:31 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_words(char const *s, char c)
{
	int			i;
	int			nb_words;
	int			len;

	nb_words = 0;
	i = 0;
	len = ft_strlen(s);
	while (len > 0)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			nb_words++;
		while (s[i] != c && s[i] != '\0')
			i++;
		len--;
	}
	return (nb_words);
}

static int		ft_nb_char(char const *s, char c)
{
	int			i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		nb_words;

	if (s == NULL)
		return (0);
	nb_words = ft_nb_words((const char *)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * nb_words + 1)))
		return (NULL);
	i = 0;
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0, ft_nb_char(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_nb_char((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
