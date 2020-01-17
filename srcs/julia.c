/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:13:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/09/02 11:24:34 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		ft_julia_axis(t_axis *ax)
{
	ax->xmax = 2;
	ax->xmin = -2;
	ax->ymax = 1.5;
	ax->ymin = -1.5;
}

int			ft_julia(t_point *p, t_img *img)
{
	t_point	tmp;
	int		i;
	float	z_r;

	i = -1;
	tmp = (t_point){0, p->x, p->y, 0, 0};
	while (tmp.mod < 4 && ++i < ITERATION + img->iter)
	{
		z_r = tmp.x;
		tmp.x = tmp.x * tmp.x - tmp.y * tmp.y + img->c_r;
		tmp.y = 2 * tmp.y * z_r + img->c_im;
		tmp.mod = tmp.x * tmp.x + tmp.y * tmp.y;
	}
	return (i);
}

int			ft_julia3(t_point *p, t_img *img)
{
	t_point	tmp;
	int		i;
	float	z_r;

	i = -1;
	tmp = (t_point){0, p->x, p->y, 0, 0};
	while (tmp.mod < 4 && ++i < ITERATION + img->iter)
	{
		z_r = tmp.x;
		tmp.x = POW(tmp.x, 3) - 3 * tmp.x * tmp.y * tmp.y + img->c_r;
		tmp.y = 3 * z_r * z_r * tmp.y - POW(tmp.y, 3) + img->c_im;
		tmp.mod = tmp.x * tmp.x + tmp.y * tmp.y;
	}
	return (i);
}

int			ft_julia4(t_point *p, t_img *img)
{
	t_point	tmp;
	int		i;
	float	z_r;

	i = -1;
	tmp = (t_point){0, p->x, p->y, 0, 0};
	while (tmp.mod < 4 && ++i < ITERATION + img->iter)
	{
		z_r = tmp.x;
		tmp.x = POW(tmp.x, 4) - 6 * tmp.x * tmp.x * tmp.y * tmp.y +
			POW(tmp.y, 4) + img->c_r;
		tmp.y = 4 * POW(z_r, 3) * tmp.y - 4 * z_r * POW(tmp.y, 3) + img->c_im;
		tmp.mod = tmp.x * tmp.x + tmp.y * tmp.y;
	}
	return (i);
}

int			ft_julia5(t_point *p, t_img *img)
{
	t_point	tmp;
	int		i;
	float	z_r;

	i = -1;
	tmp = (t_point){0, p->x, p->y, 0, 0};
	while (tmp.mod < 4 && ++i < ITERATION + img->iter)
	{
		z_r = tmp.x;
		tmp.x = POW(tmp.x, 5) - 10 * POW(tmp.x, 3) * tmp.y * tmp.y +
			5 * tmp.x * POW(tmp.y, 4) + img->c_r;
		tmp.y = 5 * POW(z_r, 4) * tmp.y - 10 * z_r * z_r * POW(tmp.y, 3) +
			POW(tmp.y, 5) + img->c_im;
		tmp.mod = tmp.x * tmp.x + tmp.y * tmp.y;
	}
	return (i);
}
