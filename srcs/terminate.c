/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:22:49 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/09/03 13:21:57 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void				ft_free_image(t_img *img)
{
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img->mlx_ptr);
	img->ax ? free(img->ax) : 0;
	free(img);
}

void				ft_term_thread(char *str, t_segment **segment, int i)
{
	int				n;

	n = -1;
	while (++n <= i)
		free(segment[n]);
	ft_putstr(str);
}

t_all				*ft_all(void)
{
	static t_all	all;

	return (&all);
}

char				*ft_error_message(void)
{
	ft_putendl("usage: ./fractol\tMandelbrot\n\t\t\tMandelbrot3");
	ft_putendl("\t\t\tMandelbrot4\n\t\t\tMandelbrot5\n\t\t\tJulia");
	ft_putendl("\t\t\tJulia3\n\t\t\tJulia4\n\t\t\tJulia5\n\t\t\tTricorn");
	ft_putendl("\t\t\tBurningship\n\t\t\tCeltic_Mandelbar");
	ft_putendl("\t\t\tPerpendicular_Buffalo\n\t\t\tPerpendicular_Celtic");
	return (NULL);
}
