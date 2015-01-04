/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 13:24:57 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/04 18:44:13 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void		ft_draw_cone(t_pt2d origin, t_pt2d arrival, t_env *env)
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

static void		ft_draw_cseven(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = BCLR;
	e = arrival.y - origin.y;
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.y += 1;
		if ((e -= dx) <= 0)
		{
			origin.x += 1;
			e += dy;
		}
	}
	return ;
}

static void		ft_draw_cfive(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = BCLR;
	e = arrival.y - origin.y;
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.y += 1;
		if ((e -= dx) <= 0)
		{
			origin.x -= 1;
			e += dy;
		}
	}
	return ;
}

void			ft_draw(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int		dx;
	int		dy;

	dx = arrival.x - origin.x;
	dy = arrival.y - origin.y;
	if (abs(dx) > abs(dy))
		dx > 0 ? ft_draw_cone(origin, arrival, env)
			: ft_draw_cone(arrival, origin, env);
	else
	{
		if (dx <= 0 && dy > 0)
			ft_draw_cfive(origin, arrival, env);
		else if (dx >= 0 && dy < 0)
			ft_draw_cseven(origin, arrival, env);
		else if (dx < 0 && dy < 0)
			ft_draw_cseven(arrival, origin, env);
		else if (dx > 0 && dy > 0)
			ft_draw_cfive(arrival, origin, env);
	}
	return ;
}
*/
void			ft_draw(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int		dx;
	int		dy;

	dx = arrival.x - origin.x;
	dy = arrival.y - origin.y;
	if (abs(dx) > abs(dy))
	{
		if (dx > 0)
			dy <= 0 ? ft_draw_cone(origin, arrival, env)
				: ft_draw_ctwo(origin, arrival, env);
		else
			dy >= 0 ? ft_draw_cthree(origin, arrival, env)
				: ft_draw_cfour(origin, arrival, env);
	}
	else
	{
		if (dy < 0)
			dx >= 0 ? ft_draw_cfive(origin, arrival, env)
				: ft_draw_csix(origin, arrival, env);
		else
			dx <= 0 ? ft_draw_cseven(origin, arrival, env)
				: ft_draw_ceight(origin, arrival, env);
	}
	return ;
}
