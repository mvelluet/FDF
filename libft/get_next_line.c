/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:10:23 by mvelluet          #+#    #+#             */
/*   Updated: 2017/03/12 12:33:28 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_n(const char *src, int n)
{
	char	*dest;
	int		i;
	int		j;

	i = ft_strlen(src);
	dest = NULL;
	if (!(dest = (char *)malloc(sizeof(char) * (i - n) + 1)))
		return (0);
	j = i - n;
	dest[j] = '\0';
	j--;
	while (j >= 0)
	{
		dest[j] = src[n + j];
		j--;
	}
	return (dest);
}

int		ft_read_rest(char **stockage, char ***line)
{
	char	*tmp;
	int		i;

	i = ft_strlen_c(*stockage, '\n');
	tmp = ft_strnew(i);
	if (*stockage && stockage[0][i - 1] == '\n')
		i--;
	tmp[--i] = '\0';
	while (i >= 0)
	{
		tmp[i] = stockage[0][i];
		i--;
	}
	**line = ft_strdup(tmp);
	free(tmp);
	tmp = *stockage;
	if (*stockage)
	{
		*stockage = ft_strdup_n(tmp, ft_strlen_c(tmp, '\n'));
		free(tmp);
	}
	return (1);
}

void	ft_treatment(char *buf, char **stockage)
{
	char		*tmp;
	size_t		i;

	i = 0;
	tmp = NULL;
	if (*stockage == NULL)
		*stockage = ft_strdup(buf);
	else
	{
		tmp = *stockage;
		*stockage = ft_strjoin(tmp, buf);
		free(tmp);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*stockage = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (BUFF_SIZE < 0 || !line || fd < 0)
		return (-1);
	ft_bzero(buf, BUFF_SIZE);
	if (stockage && ft_strrchr(stockage, '\n'))
		return (ft_read_rest(&stockage, &line));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		ft_treatment(buf, &stockage);
		if (ft_strrchr(buf, '\n'))
			break ;
	}
	if (ft_strlen(stockage) != 0)
		return (ft_read_rest(&stockage, &line));
	if (ret == 0)
		return (0);
	return (1);
}
