/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:48:14 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/07 15:57:31 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int		ft_color(t_pt2d point)
{
	unsigned int	color;

	color = 0x00FF00;
	if (point.memz < 0)
		color = 0x0000FF;
	if (point.memz > 0)
		color = 0xFFFFFF;
	return (color);
}
