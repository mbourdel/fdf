/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 18:14:19 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/04 18:14:28 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_cone(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = ACLR;
	e = arrival.x - origin.x;
	dx = e * 2;
	dy = abs(arrival.y - origin.y) * 2;
	while (origin.x <= arrival.x)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.x += 1;
		if ((e -= dy) <= 0)
		{
			origin.y -= 1;
			e += dx;
		}
	}
	return ;
}

void		ft_draw_ctwo(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = ACLR;
	e = arrival.x - origin.x;
	dx = e * 2;
	dy = abs(arrival.y - origin.y) * 2;
	while (origin.x <= arrival.x)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.x += 1;
		if ((e -= dy) <= 0)
		{
			origin.y += 1;
			e += dx;
		}
	}
	return ;
}

void		ft_draw_cthree(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = ACLR;
	e = arrival.x - origin.x;
	dx = e * 2;
	dy = abs(arrival.y - origin.y) * 2;
	while (origin.x >= arrival.x)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.x -= 1;
		if ((e -= dy) <= 0)
		{
			origin.y += 1;
			e += dx;
		}
	}
	return ;
}

void		ft_draw_cfour(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = ACLR;
	e = arrival.x - origin.x;
	dx = e * 2;
	dy = abs(arrival.y - origin.y) * 2;
	while (origin.x >= arrival.x)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.x -= 1;
		if ((e -= dy) <= 0)
		{
			origin.y -= 1;
			e += dx;
		}
	}
	return ;
}