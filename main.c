/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 11:49:43 by mvelluet          #+#    #+#             */
/*   Updated: 2017/03/24 23:06:04 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initialisation(t_mlx_fdf *ap)
{
	int		bpp;
	int		s_l;
	int		endian;

	ap->mlx = mlx_init();
	ap->height = HEIGHT;
	ap->width = WIDTH;
	ap->win = mlx_new_window(ap->mlx, ap->width, ap->height, "mlx 42");
	ap->ptr_img = mlx_new_image(ap->mlx, ap->width, ap->height);
	ap->img_str = mlx_get_data_addr(ap->ptr_img, &(bpp), &(s_l), &(endian));
	ap->x = 0;
	ap->y = 0;
	ap->red = 250;
	ap->green = 250;
	ap->blue = 250;
	ap->alpha = 0;
	ap->ax = 35.000000;
	ap->ay = 340.000000;
	ap->az = -35.000000;
	ap->zoom = 5;
	ap->marge_x = 200;
	ap->marge_y = 200;
	ap->error = 0;
	ap->coef = 1.0;
}

int		ft_verif_arg(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		return (1);
	len = ft_strlen(argv[1]);
	len--;
	if (argv[1][len] != 'f')
		return (1);
	if (argv[1][len - 1] != 'd')
		return (1);
	if (argv[1][len - 2] != 'f')
		return (1);
	if (argv[1][len - 3] != '.')
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx_fdf	ap;

	if (ft_verif_arg(argc, argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_initialisation(&ap);
	ft_map(argv, &ap);
	if (ap.error == 1 || HEIGHT > 1200 || WIDTH > 1200)
	{
		ft_putstr("Error\n");
		return (0);
	}
	ft_malloc_map(&ap);
	ft_malloc_map_coord(&ap);
	ft_map_read_2(argv, &ap);
	ft_init_map(&ap);
	ft_register_hight(&ap);
	ft_draw_map(&ap);
	ft_link_point(&ap);
	mlx_put_image_to_window(ap.mlx, ap.win, ap.ptr_img, 0, 0);
	mlx_hook(ap.win, 2, (1L << 0), ft_key_event, &ap);
	mlx_loop(ap.mlx);
	return (0);
}
