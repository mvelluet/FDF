/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:42:13 by mvelluet          #+#    #+#             */
/*   Updated: 2017/03/26 19:52:02 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel_line(t_mlx_fdf *ap)
{
	unsigned	pos_x;
	unsigned	pos_y;

	pos_x = (unsigned)ap->x_tmp * (WIDTH * 4);
	pos_y = (unsigned)ap->y_tmp * 4;
	if (ap->y_tmp > 0 && ap->y_tmp < WIDTH)
	{
		ap->pos = pos_x + pos_y;
		if (ap->pos > 0 && ap->pos < (HEIGHT * WIDTH * 4))
		{
			ap->img_str[ap->pos] = ap->red;
			ap->img_str[ap->pos + 1] = ap->green;
			ap->img_str[ap->pos + 2] = ap->blue;
			ap->img_str[ap->pos + 3] = ap->alpha;
		}
	}
}

void	ft_draw_line(t_mlx_fdf *ap, int y0, int x1, int y1)
{
	ap->x_tmp = ap->x0;
	ap->y_tmp = y0;
	ap->d_x = abs(x1 - ap->x0);
	ap->d_y = abs(y1 - y0);
	ap->x_inc = (ap->x0 < x1) ? 1 : -1;
	ap->y_inc = (y0 < y1) ? 1 : -1;
	ap->cumul = (ap->d_x > ap->d_y ? ap->d_x : -(ap->d_y)) / 2;
	while (!(ap->y_tmp == y1 && ap->x_tmp == x1))
	{
		ft_put_pixel_line(ap);
		ap->tmp_cumul = ap->cumul;
		if (ap->tmp_cumul > -(ap->d_x))
		{
			ap->cumul -= (ap->d_y);
			ap->x_tmp += ap->x_inc;
		}
		if (ap->tmp_cumul < (ap->d_y))
		{
			ap->cumul += (ap->d_x);
			ap->y_tmp += ap->y_inc;
		}
	}
}

void	ft_link_point(t_mlx_fdf *ap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ap->total - ap->nb_cols)
	{
		ap->x0 = ap->coords[i].x;
		ft_draw_line(ap, ap->coords[i].y,
			ap->coords[i + ap->nb_cols].x, ap->coords[i + ap->nb_cols].y);
		i++;
	}
	i = 0;
	while (i < ap->total - 1)
	{
		j = 0;
		while (j < ap->nb_cols - 1)
		{
			ap->x0 = ap->coords[i + j].x;
			ft_draw_line(ap, ap->coords[i + j].y,
				ap->coords[i + j + 1].x, ap->coords[i + j + 1].y);
			j++;
		}
		i += ap->nb_cols;
	}
}

void	ft_iso_persp(t_mlx_fdf *ap, int i, int y, int z)
{
	float	xp;
	float	yp;
	float	zp;

	ap->coords[i].x = ap->x1;
	ap->coords[i].y = cos(angle(ap->ax)) * y - sin(angle(ap->ax)) * z;
	ap->coords[i].z = sin(angle(ap->ax)) * y + cos(angle(ap->ax)) * z;
	xp = cos(angle(ap->ay)) * ap->coords[i].x +
	sin(angle(ap->ay)) * ap->coords[i].z;
	yp = ap->coords[i].y;
	zp = -(sin(angle(ap->ay))) * ap->coords[i].x +
	cos(angle(ap->ay)) * ap->coords[i].z;
	ap->coords[i].x = cos(angle(ap->az)) * xp - sin(angle(ap->az)) * yp;
	ap->coords[i].y = sin(angle(ap->az)) * xp + cos(angle(ap->az)) * yp;
	ap->coords[i].z = zp;
	ap->coords[i].x = ap->coords[i].x * ap->zoom + ap->marge_x;
	ap->coords[i].y = ap->coords[i].y * ap->zoom + ap->marge_y;
}

void	ft_draw_map(t_mlx_fdf *ap)
{
	int	x;
	int	y;
	int i;
	int j;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	while (x < ap->nb_line)
	{
		y = 0;
		while (y < ap->nb_cols)
		{
			ap->x1 = ap->coords[i].x;
			ft_iso_persp(ap, i, ap->coords[i].y,
				ap->coords[i].z);
			ft_put_pixel(ap, i);
			i++;
			y++;
		}
		x++;
		j++;
	}
}
