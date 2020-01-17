/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_appearance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:41:57 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/08/29 15:23:18 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		ft_zoom(int button, t_img *ptr)
{
	if (button == 4)
	{
		ptr->ax->xmin += X_ZOOM * ptr->ax->xamp / WIDTH;
		ptr->ax->xmax -= X_ZOOM * ptr->ax->xamp / WIDTH;
		ptr->ax->ymin += Y_ZOOM * ptr->ax->yamp / HEIGHT;
		ptr->ax->ymax -= Y_ZOOM * ptr->ax->yamp / HEIGHT;
	}
	if (button == 5)
	{
		ptr->ax->xmin -= X_ZOOM * ptr->ax->xamp / WIDTH;
		ptr->ax->xmax += X_ZOOM * ptr->ax->xamp / WIDTH;
		ptr->ax->ymin -= Y_ZOOM * ptr->ax->yamp / HEIGHT;
		ptr->ax->ymax += Y_ZOOM * ptr->ax->yamp / HEIGHT;
	}
	ptr->ax->xamp = ptr->ax->xmax - ptr->ax->xmin;
	ptr->ax->yamp = ptr->ax->ymax - ptr->ax->ymin;
}

void		ft_move(int key, t_img *ptr)
{
	if (key == 124)
	{
		ptr->ax->xmin += MOVE * ptr->ax->xamp / WIDTH;
		ptr->ax->xmax += MOVE * ptr->ax->xamp / WIDTH;
	}
	if (key == 123)
	{
		ptr->ax->xmin -= MOVE * ptr->ax->xamp / WIDTH;
		ptr->ax->xmax -= MOVE * ptr->ax->xamp / WIDTH;
	}
	if (key == 126)
	{
		ptr->ax->ymin += MOVE * ptr->ax->yamp / HEIGHT;
		ptr->ax->ymax += MOVE * ptr->ax->yamp / HEIGHT;
	}
	if (key == 125)
	{
		ptr->ax->ymin -= MOVE * ptr->ax->yamp / HEIGHT;
		ptr->ax->ymax -= MOVE * ptr->ax->yamp / HEIGHT;
	}
}

void		ft_change_iteration(int key, t_img *ptr)
{
	if (key == 78 && -ptr->iter < ITERATION)
		ptr->iter -= 5;
	if (key == 69)
		ptr->iter += 5;
}

void		ft_enable_or_disable_mouse_move(int key, t_img *ptr)
{
	if (ptr->mouse_track == 1)
		ptr->mouse_track = 0;
	else
		ptr->mouse_track = 1;
}
