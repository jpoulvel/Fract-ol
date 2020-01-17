/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:43:35 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/09/02 12:19:44 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_img				*ft_ptr_init(char *title)
{
	t_img			*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	img->ttl = title;
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, WIDTH, HEIGHT, title);
	img->img_ptr = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->bpp = 32;
	img->s_l = WIDTH * 4;
	img->height = HEIGHT;
	img->col = 1;
	img->iter = 0;
	img->mouse_track = 1;
	img->endian = 0;
	img->ax = ft_axis_init(title);
	img->str = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->s_l),
			&(img->endian));
	ft_bzero(img->str, (img->s_l * HEIGHT));
	return (img);
}

t_point				*ft_point_init(void)
{
	t_point			*p;

	if (!(p = malloc(sizeof(t_point))))
		return (NULL);
	p->p = 0;
	p->x = 0;
	p->y = 0;
	p->color = 0x000000;
	return (p);
}

t_axis				*ft_axis_init(char *title)
{
	t_axis			*ax;

	if (!(ax = malloc(sizeof(t_axis))))
		return (NULL);
	if (ft_strncmp(title, "Julia", 5) == 0)
		ft_julia_axis(ax);
	else
		ft_mandel_axis(ax);
	ax->xamp = ax->xmax - ax->xmin;
	ax->yamp = ax->ymax - ax->ymin;
	ax->gap_x = ax->xamp / WIDTH;
	ax->gap_y = ax->yamp / HEIGHT;
	return (ax);
}

t_segment			*ft_threads_init(t_segment **seg)
{
	int				i;

	i = -1;
	while (++i < THREADS)
	{
		if (!(seg[i] = malloc(sizeof(t_segment))))
			return (NULL);
		if (!(seg[i]->p = ft_point_init()))
			return (NULL);
	}
	return (*seg);
}
