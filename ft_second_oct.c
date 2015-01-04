/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 18:19:11 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/04 18:19:15 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_cfive(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = ACLR;
	e = arrival.y - origin.y;
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y >= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.y -= 1;
		if ((e -= dy) <= 0)
		{
			origin.x += 1;
			e += dx;
		}
	}
	return ;
}

void		ft_draw_csix(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = ACLR;
	e = arrival.y - origin.y;
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y >= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.y -= 1;
		if ((e -= dy) <= 0)
		{
			origin.x -= 1;
			e += dx;
		}
	}
	return ;
}

void		ft_draw_cseven(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = ACLR;
	e = arrival.y - origin.y;
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.y += 1;
		if ((e -= dy) <= 0)
		{
			origin.x -= 1;
			e += dx;
		}
	}
	return ;
}

void		ft_draw_ceight(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = ACLR;
	e = arrival.y - origin.y;
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.y += 1;
		if ((e -= dy) <= 0)
		{
			origin.x += 1;
			e += dx;
		}
	}
	return ;
}