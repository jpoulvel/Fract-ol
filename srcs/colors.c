/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:57:45 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/08/28 13:41:29 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			ft_color(int i)
{
	int		start;
	int		end;

	end = 0x000000;
	start = 0xffff00;
	if (i == 0 || i == ITERATION)
		return (0x000000);
	else
		return ((start * (start - i) + end * i) / ITERATION);
}
