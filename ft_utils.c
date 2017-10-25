/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:47:41 by mvelluet          #+#    #+#             */
/*   Updated: 2017/03/24 15:59:02 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_image(t_mlx_fdf *ap)
{
	int bpp;
	int s_l;
	int endian;

	mlx_destroy_image(ap->mlx, ap->ptr_img);
	ap->ptr_img = mlx_new_image(ap->mlx, ap->width, ap->height);
	ap->img_str = mlx_get_data_addr(ap->ptr_img, &(bpp), &(s_l), &(endian));
	ft_init_map(ap);
	ft_draw_map(ap);
	ft_link_point(ap);
	mlx_put_image_to_window(ap->mlx, ap->win, ap->ptr_img, 0, 0);
}

void	ft_put_pixel(t_mlx_fdf *ap, int i)
{
	unsigned	pos_x;
	unsigned	pos_y;

	pos_x = (unsigned)ap->coords[i].x * (WIDTH * 4);
	pos_y = (unsigned)ap->coords[i].y * 4;
	if (ap->coords[i].y > 0 && ap->coords[i].y < WIDTH)
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

void	ft_change_color(int keycode, t_mlx_fdf *ap)
{
	if (keycode == 43)
	{
		ap->red += 10;
		ap->green += 30;
		ap->blue += 50;
	}
	if (keycode == 47)
	{
		ap->red -= 30;
		ap->green -= 50;
		ap->blue -= 10;
	}
}

float	angle(float deg)
{
	float i;

	i = PI * deg / 180;
	return (i);
}
