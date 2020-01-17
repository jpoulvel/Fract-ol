/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:19:35 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/09/03 13:13:24 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			ft_key_press(int key, t_img *ptr)
{
	if (key == 53)
	{
		ft_free_image(ptr);
		exit(0);
	}
	if (key >= 123 && key <= 126)
		ft_move(key, ptr);
	if (key == 69 || key == 78)
		ft_change_iteration(key, ptr);
	if (key == 8)
		ptr->col *= 0.1;
	if (key == 9)
		ptr->col *= 10;
	ft_clear_and_replace(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
	ft_print_menu(ptr->mlx_ptr, ptr->win_ptr);
	return (1);
}

int			ft_mouse_in_window(int x, int y)
{
	if (x <= WIDTH && y <= HEIGHT)
		return (1);
	return (0);
}

int			ft_mouse_move(int x, int y, t_img *img)
{
	img->mouse_x0 = img->mouse_x1;
	img->mouse_y0 = img->mouse_y1;
	img->mouse_x1 = x;
	img->mouse_y1 = y;
	if (img->mouse_track && ft_mouse_in_window(x, y))
	{
		if (img->mouse_x0 != img->mouse_x1)
			img->c_r = GAP_X * (img->mouse_x1 - (WIDTH / 2));
		if (img->mouse_y0 != img->mouse_y1)
			img->c_im = GAP_Y * (img->mouse_y1 - (HEIGHT / 2));
		ft_clear_and_replace(img);
	}
	return (0);
}

int			ft_mouse_press(int button, int x, int y, t_img *img)
{
	if (!(ft_mouse_in_window(x, y)))
		return (0);
	if (button == 4 || button == 5)
		ft_zoom(button, img);
	if (button == 1)
		ft_enable_or_disable_mouse_move(button, img);
	ft_clear_and_replace(img);
	return (0);
}

void		ft_get_controls(t_img *ptr)
{
	mlx_hook(ptr->win_ptr, 2, 0, ft_key_press, ptr);
	mlx_hook(ptr->win_ptr, 6, 0, ft_mouse_move, ptr);
	mlx_hook(ptr->win_ptr, 4, 0, ft_mouse_press, ptr);
}
