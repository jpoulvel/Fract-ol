/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:07:53 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/09/03 13:21:31 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void			ft_draw(t_segment *seg)
{
	t_point		*p;

	p = seg->p;
	p->p = seg->start;
	while (p->p + 3 < seg->end)
	{
		p->x = seg->img->ax->xmin + (p->p % seg->img->s_l) *
			seg->img->ax->xamp / seg->img->s_l;
		p->y = seg->img->ax->ymax - (p->p / seg->img->s_l) *
			seg->img->ax->yamp / HEIGHT;
		p->mod = (p->x * p->x + p->y * p->y);
		p->color = ft_color(seg->img->fractal(p, seg->img)) * seg->img->col;
		seg->img->str[p->p] = p->color & 0xff;
		seg->img->str[p->p + 1] = (p->color & 0xff00) >> 8;
		seg->img->str[p->p + 2] = (p->color & 0xff0000) >> 16;
		seg->img->str[p->p + 3] = 5;
		p->p += 4;
	}
}

int				ft_create_threads(t_img *img)
{
	pthread_t	th[THREADS];
	t_segment	**seg;
	int			i;

	seg = ft_all()->seg;
	i = -1;
	while (++i < THREADS)
	{
		seg[i]->img = img;
		seg[i]->start = i * img->s_l * (HEIGHT / THREADS);
		seg[i]->end = (i + 1) * (img->s_l * HEIGHT / THREADS) - 1;
		pthread_create(&th[i], NULL, (void *(*)(void *))ft_draw, seg[i]);
	}
	i = -1;
	while (++i <= THREADS)
		pthread_join(th[i], NULL);
	return (0);
}

void			ft_print_menu(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 15, 15, OCRE, "ZOOM : scroll");
	mlx_string_put(mlx_ptr, win_ptr, 15, 40, OCRE, "MOVE : arrows");
	mlx_string_put(mlx_ptr, win_ptr, 15, 65, OCRE, "COLOR : C / V");
	mlx_string_put(mlx_ptr, win_ptr, 15, 90, OCRE, "CHANGE ITERATION : + / -");
	mlx_string_put(mlx_ptr, win_ptr, 15, 115, OCRE, "JULIA PARAM : mouse move");
	mlx_string_put(mlx_ptr, win_ptr, 15, 140, OCRE,
			"BLOCK MOUSE MOVE : click left");
}

void			ft_clear_and_replace(t_img *ptr)
{
	ft_bzero(ptr->str, HEIGHT * ptr->s_l);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	ft_fractal(ptr);
}
