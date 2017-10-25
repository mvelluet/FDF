/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 10:29:42 by mvelluet          #+#    #+#             */
/*   Updated: 2017/03/24 22:51:59 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_malloc_map(t_mlx_fdf *ap)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!(ap->map = (int **)malloc(sizeof(int *) * ap->nb_line)))
		exit(-1);
	while (j < ap->nb_line)
	{
		i = 0;
		if (!(ap->map[j] = (int *)malloc(sizeof(int) * ap->nb_cols)))
			exit(-1);
		while (i < ap->nb_cols)
		{
			ap->map[j][i] = 0;
			i++;
		}
		j++;
	}
}

void	ft_malloc_map_coord(t_mlx_fdf *ap)
{
	ap->total = ap->nb_line * ap->nb_cols;
	if (!(ap->coords = (t_coords *)malloc(sizeof(t_coords) * ap->total)))
		exit(-1);
}

void	ft_malloc_tab_hight(t_mlx_fdf *ap)
{
	int i;

	i = 0;
	ap->hight_total = 0;
	while (i < ap->total)
	{
		if (ap->coords[i].z > 0 || ap->coords[i].z < 0)
			ap->hight_total++;
		i++;
	}
	if (!(ap->tab_hight = (int *)malloc(sizeof(int) * ap->hight_total)))
		exit(-1);
	if (!(ap->tab_init = (int *)malloc(sizeof(int) * ap->hight_total)))
		exit(-1);
}

void	ft_register_hight(t_mlx_fdf *ap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_malloc_tab_hight(ap);
	while (i < ap->total)
	{
		if (ap->coords[i].z > 0 || ap->coords[i].z < 0)
		{
			ap->tab_hight[j] = i;
			ap->tab_init[j] = ap->coords[i].z;
			j++;
		}
		i++;
	}
}

void	ft_init_map(t_mlx_fdf *ap)
{
	int	i;
	int	value_x;
	int	value_y;
	int	value_stop;

	i = 0;
	value_x = 1;
	value_y = 1;
	value_stop = (ap->nb_cols + 1);
	while (i < ap->total)
	{
		ap->coords[i].y = value_y;
		ap->coords[i].x = value_x;
		ap->coords[i].z = ap->coords[i].z_tmp;
		value_y++;
		if (value_y == value_stop)
		{
			value_x++;
			value_y = 1;
		}
		i++;
	}
}
