/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 09:59:50 by mvelluet          #+#    #+#             */
/*   Updated: 2017/03/29 18:59:20 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"

# define HEIGHT 1200
# define WIDTH 1200
# define PI 3.1415926535898

typedef struct		s_coords
{
	float			x;
	float			y;
	float			z;
	float			z_tmp;
}					t_coords;

typedef struct		s_mlx_fdf
{
	unsigned		pos;
	char			*img_str;
	void			*mlx;
	void			*win;
	void			*ptr_img;
	int				**map;
	t_coords		*coords;
	float			coef;
	float			ax;
	float			ay;
	float			az;
	int				x;
	int				y;
	int				x0;
	int				x1;
	int				d_x;
	int				d_y;
	int				x_tmp;
	int				y_tmp;
	int				x_inc;
	int				y_inc;
	int				cumul;
	int				tmp_cumul;
	int				red;
	int				green;
	int				blue;
	int				alpha;
	int				total;
	int				width;
	int				height;
	int				nb_line;
	int				nb_cols;
	int				zoom;
	int				marge_x;
	int				marge_y;
	int				error;
	int				*tab_hight;
	int				*tab_init;
	int				hight_total;
}					t_mlx_fdf;

void				ft_initialisation(t_mlx_fdf *ap);
int					ft_verif_arg(int argc, char **argv);
int					ft_map(char **argv, t_mlx_fdf *ap);
void				ft_count_space(char *line, t_mlx_fdf *ap);
int					ft_get_number(char *line, int i);
int					ft_save_map(t_mlx_fdf *ap, char *line, int k);
int					ft_map_read_2(char **argv, t_mlx_fdf *ap);
void				ft_malloc_map(t_mlx_fdf *ap);
void				ft_malloc_map_coord(t_mlx_fdf *ap);
void				ft_register_hight(t_mlx_fdf *ap);
void				ft_init_map(t_mlx_fdf *ap);
void				ft_put_pixel_line(t_mlx_fdf *ap);
void				ft_link_point(t_mlx_fdf *ap);
void				ft_draw_line(t_mlx_fdf *ap, int y0, int x1, int y1);
void				ft_draw_map(t_mlx_fdf *ap);
void				ft_iso_persp(t_mlx_fdf *ap, int i, int y, int z);
void				ft_print_image(t_mlx_fdf *ap);
void				ft_change_color(int keycode, t_mlx_fdf *ap);
float				angle(float deg);
void				ft_put_pixel(t_mlx_fdf *ap, int i);
void				ft_deplacement(int keycode, t_mlx_fdf *ap);
void				ft_zoom(int keycode, t_mlx_fdf *ap);
void				ft_rotate(int keycode, t_mlx_fdf *ap);
void				ft_moutain(int keycode, t_mlx_fdf *ap);
int					ft_key_event(int keycode, t_mlx_fdf *ap);

#endif
