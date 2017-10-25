/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:49:26 by mvelluet          #+#    #+#             */
/*   Updated: 2017/03/24 22:53:39 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_deplacement(int keycode, t_mlx_fdf *ap)
{
	if (keycode == 124)
		ap->marge_y = ap->marge_y + 5;
	if (keycode == 123)
		ap->marge_y = ap->marge_y - 5;
	if (keycode == 125)
		ap->marge_x = ap->marge_x + 5;
	if (keycode == 126)
		ap->marge_x = ap->marge_x - 5;
}

void	ft_zoom(int keycode, t_mlx_fdf *ap)
{
	if (keycode == 69)
		ap->zoom = ap->zoom + 1;
	if (ap->zoom > 0)
	{
		if (keycode == 78)
			ap->zoom = ap->zoom - 1;
	}
}

void	ft_rotate(int keycode, t_mlx_fdf *ap)
{
	if (ap->ax > 360 || ap->ax < -360)
		ap->ax = 0;
	if (ap->ay > 360 || ap->ay < -360)
		ap->ay = 0;
	if (ap->az > 360 || ap->az < -360)
		ap->az = 0;
	if (keycode == 89)
		ap->ax = ap->ax + 5;
	if (keycode == 91)
		ap->ax = ap->ax - 5;
	if (keycode == 86)
		ap->ay = ap->ay + 5;
	if (keycode == 87)
		ap->ay = ap->ay - 5;
	if (keycode == 83)
		ap->az = ap->az + 5;
	if (keycode == 84)
		ap->az = ap->az - 5;
}

void	ft_moutain(int keycode, t_mlx_fdf *ap)
{
	int	i;

	i = 0;
	if (keycode == 12)
		ap->coef += 0.1;
	if (keycode == 13)
		ap->coef -= 0.1;
	while (i < ap->hight_total)
	{
		ap->coords[ap->tab_hight[i]].z_tmp = ap->tab_init[i] * ap->coef;
		i++;
	}
}

int		ft_key_event(int keycode, t_mlx_fdf *ap)
{
	if (keycode == 69 || keycode == 78)
		ft_zoom(keycode, ap);
	if (keycode >= 123 || keycode <= 126)
		ft_deplacement(keycode, ap);
	if (keycode >= 83 || keycode <= 91)
		ft_rotate(keycode, ap);
	if (keycode == 43 || keycode == 47)
		ft_change_color(keycode, ap);
	if (keycode == 12 || keycode == 13)
		ft_moutain(keycode, ap);
	if (keycode == 53)
		exit(-1);
	ft_print_image(ap);
	return (keycode);
}
