/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_fonctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:03:54 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/09/03 11:55:38 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_check_title(char *title)
{
	if (ft_strcmp(title, "Mandelbrot") == 0 ||
			ft_strcmp(title, "Julia") == 0 ||
			ft_strcmp(title, "Julia3") == 0 ||
			ft_strcmp(title, "Julia4") == 0 ||
			ft_strcmp(title, "Julia5") == 0 ||
			ft_strcmp(title, "Mandelbrot3") == 0 ||
			ft_strcmp(title, "Mandelbrot4") == 0 ||
			ft_strcmp(title, "Mandelbrot5") == 0 ||
			ft_strcmp(title, "Tricorn") == 0 ||
			ft_strcmp(title, "Perpendicular_Buffalo") == 0 ||
			ft_strcmp(title, "Perpendicular_Celtic") == 0 ||
			ft_strcmp(title, "Celtic_Mandelbar") == 0 ||
			ft_strcmp(title, "Burningship") == 0)
		return (1);
	return (0);
}
