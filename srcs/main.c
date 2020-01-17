/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:24:15 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/09/03 13:05:46 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void			ft_select_fractal(t_img *img)
{
	ft_strcmp(img->ttl, "Mandelbrot") == 0 ? img->fractal = &ft_mandel : 0;
	ft_strcmp(img->ttl, "Mandelbrot3") == 0 ? img->fractal = &ft_mandel3 : 0;
	ft_strcmp(img->ttl, "Mandelbrot4") == 0 ? img->fractal = &ft_mandel4 : 0;
	ft_strcmp(img->ttl, "Mandelbrot5") == 0 ? img->fractal = &ft_mandel5 : 0;
	ft_strcmp(img->ttl, "Julia") == 0 ? img->fractal = &ft_julia : 0;
	ft_strcmp(img->ttl, "Julia3") == 0 ? img->fractal = &ft_julia3 : 0;
	ft_strcmp(img->ttl, "Julia4") == 0 ? img->fractal = &ft_julia4 : 0;
	ft_strcmp(img->ttl, "Julia5") == 0 ? img->fractal = &ft_julia5 : 0;
	ft_strcmp(img->ttl, "Burningship") == 0 ?
		img->fractal = &ft_burningship : 0;
	ft_strcmp(img->ttl, "Tricorn") == 0 ? img->fractal = &ft_tricorn : 0;
	ft_strcmp(img->ttl, "Celtic_Mandelbar") == 0 ?
		img->fractal = &ft_celtic_mandelbar : 0;
	ft_strcmp(img->ttl, "Perpendicular_Buffalo") == 0 ?
		img->fractal = &ft_perpendicular_buffalo : 0;
	ft_strcmp(img->ttl, "Perpendicular_Celtic") == 0 ?
		img->fractal = &ft_perpendicular_celtic : 0;
}

int				ft_fractal(t_img *img)
{
	ft_create_threads(img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	ft_print_menu(img->mlx_ptr, img->win_ptr);
	ft_get_controls(img);
	mlx_loop(img->mlx_ptr);
	return (0);
}

t_img			*ft_init(char *title)
{
	t_img		*img;
	t_all		*all;

	all = ft_all();
	if (!(ft_threads_init(all->seg)))
		return (NULL);
	if (!(img = ft_ptr_init(title)))
		return (NULL);
	ft_select_fractal(img);
	return (img);
}

int				main(int argc, char **argv)
{
	t_img		*img;

	if (argc != 2 || ft_check_title(argv[1]) == 0)
		return (ft_error(ft_error_message(), 2));
	if (!(img = ft_init(argv[1])))
		return (ft_error("Initiation failed", 2));
	ft_fractal(img);
	return (1);
}
