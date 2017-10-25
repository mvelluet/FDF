/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 10:24:55 by mvelluet          #+#    #+#             */
/*   Updated: 2017/03/24 22:46:17 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_count_space(char *line, t_mlx_fdf *ap)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	while (len > 0)
	{
		if (line[j] != ' ' && line[j] < 48 && line[j] > 57)
			ap->error = 1;
		while (line[j] == ' ' && line[i] != '\0')
			j++;
		if (line[j] != ' ' && line[j] != '\0')
			i++;
		while (line[j] != ' ' && line[j] != '\0')
			j++;
		len--;
	}
	if (i > ap->nb_cols)
		ap->nb_cols = i;
}

int		ft_map(char **argv, t_mlx_fdf *ap)
{
	char	*line;
	char	*map[10496];
	int		nb_line;
	int		fd;

	nb_line = 0;
	ap->nb_line = 0;
	ap->nb_cols = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ap->error = 1;
	while (get_next_line(fd, &line) == 1)
	{
		map[nb_line] = line;
		ft_count_space(line, ap);
		free(line);
		nb_line++;
	}
	ap->nb_line = nb_line;
	close(fd);
	return (0);
}

int		ft_get_number(char *line, int i)
{
	char	number[100];
	int		len;
	int		j;
	int		pos_i;
	int		num;

	len = 0;
	pos_i = i;
	ft_bzero(number, 100);
	while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
	{
		i++;
		len++;
	}
	j = 0;
	while (j <= len)
	{
		number[j] = line[pos_i + j];
		j++;
	}
	num = ft_atoi(number);
	return (num);
}

int		ft_save_map(t_mlx_fdf *ap, char *line, int k)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		ap->coords[k].z = ft_get_number(line, i);
		ap->coords[k].z_tmp = ap->coords[k].z;
		while (line[i] != ' ' && line[i] != '\0')
			i++;
		while (line[i] == ' ')
			i++;
		k++;
	}
	return (k);
}

int		ft_map_read_2(char **argv, t_mlx_fdf *ap)
{
	char	*line;
	int		fd;
	int		j;
	int		k;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	j = 0;
	k = 0;
	while (get_next_line(fd, &line) == 1)
	{
		k = ft_save_map(ap, line, k);
		free(line);
		j++;
	}
	close(fd);
	return (0);
}
