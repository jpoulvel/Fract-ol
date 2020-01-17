/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:18:29 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/09/03 11:53:17 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int				ft_tricorn(t_point *p, t_img *img)
{
	t_point		tmp;
	int			i;
	double		z_r;

	i = -1;
	tmp = (t_point){0, p->x, p->y, 0, 0};
	while (tmp.mod < 4 && ++i < ITERATION + img->iter)
	{
		z_r = tmp.x;
		tmp.x = tmp.x * tmp.x - tmp.y * tmp.y + p->x + img->c_r;
		tmp.y = -2 * tmp.y * z_r + p->y + img->c_im;
		tmp.mod = tmp.x * tmp.x + tmp.y * tmp.y;
	}
	return (i);
}

int				ft_celtic_mandelbar(t_point *p, t_img *img)
{
	t_point		tmp;
	int			i;
	double		z_r;

	i = -1;
	tmp = (t_point){0, p->x, p->y, 0, 0};
	while (tmp.mod < 4 && ++i < ITERATION + img->iter)
	{
		z_r = tmp.x;
		tmp.x = ft_abs(tmp.x * tmp.x - tmp.y * tmp.y) + p->x + img->c_r;
		tmp.y = -2 * tmp.y * z_r + p->y + img->c_im;
		tmp.mod = tmp.x * tmp.x + tmp.y * tmp.y;
	}
	return (i);
}

int				ft_burningship(t_point *p, t_img *img)
{
	t_point		tmp;
	int			i;
	float		z_r;

	i = -1;
	tmp = (t_point){0, p->x, p->y, 0, 0};
	while (tmp.mod < 4 && ++i < ITERATION + img->iter)
	{
		z_r = ft_abs(tmp.x);
		tmp.x = tmp.x * tmp.x - tmp.y * tmp.y + p->x + img->c_r;
		tmp.y = -2 * ft_abs(tmp.y * z_r) + p->y + img->c_im;
		tmp.mod = tmp.x * tmp.x + tmp.y * tmp.y;
	}
	return (i);
}

int				ft_perpendicular_buffalo(t_point *p, t_img *img)
{
	t_point		tmp;
	int			i;
	float		z_r;

	i = -1;
	tmp = (t_point){0, p->x, p->y, 0, 0};
	while (tmp.mod < 4 && ++i < ITERATION + img->iter)
	{
		z_r = tmp.x;
		tmp.x = ft_abs(tmp.x * tmp.x - tmp.y * tmp.y) + p->x + img->c_r;
		tmp.y = tmp.x * ft_abs(tmp.y) * -2 + p->y + img->c_im;
		tmp.mod = tmp.x * tmp.x + tmp.y * tmp.y;
	}
	return (i);
}

int				ft_perpendicular_celtic(t_point *p, t_img *img)
{
	t_point		tmp;
	int			i;
	float		z_r;

	i = -1;
	tmp = (t_point){0, p->x, p->y, 0, 0};
	while (tmp.mod < 4 && ++i < ITERATION + img->iter)
	{
		z_r = tmp.x;
		tmp.x = ft_abs(tmp.x * tmp.x - tmp.y * tmp.y) + p->x + img->c_r;
		tmp.y = ft_abs(tmp.x) * tmp.y * -2 + p->y + img->c_im;
		tmp.mod = tmp.x * tmp.x + tmp.y * tmp.y;
	}
	return (i);
}
