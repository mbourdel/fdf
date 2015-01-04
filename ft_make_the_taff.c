/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_the_taff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:03:51 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/04 17:04:16 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void		ft_draw_line(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int		dx;
	int		dy;
	int		e;

	e = arrival.x - origin.x;
	dx = e * 2;
	dy = abs(arrival.y - origin.y) * 2;
	while (origin.x <= arrival.x)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), ACLR);
		origin.x = origin.x + 1;
		if ((e = (e - dy)) <= 0)
		{
			origin.y = origin.y + 1;
			e = e + dx;
		}
	}
	return ;
}

static void		ft_draw_flope(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	color = BCLR;
	e = abs(arrival.y - origin.y);
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), color);
		origin.y = origin.y + 1;
		if ((e = (e - dx)) <= 0)
		{
			origin.x = origin.x - 1;
			e = e + dy;
		}
	}
	return ;
}

static void		ft_draw_slope(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int		dx;
	int		dy;
	int		e;

	e = (arrival.y - origin.y);
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->xvar),
				(origin.y + env->yvar), BCLR);
		origin.y = origin.y + 1;
		if ((e = (e - dx)) <= 0)
		{
			origin.x = origin.x + 1;
			e = e + dy;
		}
	}
	return ;
}

static void		ft_choose_itself_like_a_big_boy(t_ls2d pt2d, int i, t_env *env)
{
	if (pt2d[i].memz == pt2d[i - 1].memz)
		ft_draw_line(pt2d[i - 1], pt2d[i], env);
	if (pt2d[i].memz > pt2d[i - 1].memz)
		ft_draw_flope(pt2d[i], pt2d[i - 1], env);
	if (pt2d[i].memz < pt2d[i - 1].memz)
		ft_draw_slope(pt2d[i - 1], pt2d[i], env);
	if (pt2d[i].stay_high != NULL)
	{
		if (pt2d[i].memz == pt2d[i].stay_high->memz)
			ft_draw_line(pt2d[i].stay_high[0], pt2d[i], env);
		if (pt2d[i].memz > pt2d[i].stay_high->memz)
			ft_draw_flope(pt2d[i], pt2d[i].stay_high[0], env);
		if (pt2d[i].memz < pt2d[i].stay_high->memz)
			ft_draw_slope(pt2d[i].stay_high[0], pt2d[i], env);
	}
	return ;
}

void			ft_draw_pt2d(t_env *env)
{
	int		i;

	i = 0;
	while (env->pt2d[i].x != 0)
	{
		ft_pixel_put_img(env, (env->pt2d[i].x + env->xvar),
				(env->pt2d[i].y + env->yvar), COLOR);
		if (i > 0)
			ft_choose_itself_like_a_big_boy(env->pt2d, i, env);
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img_ptr, 0, 0);
	return ;
}*/

void			ft_draw_pt2d(t_env *env)
{
	int		i;

	i = 0;
	while (env->pt2d[i].x != 0)
	{
	//	ft_pixel_put_img(env, (env->pt2d[i].x + env->xvar),
	//			(env->pt2d[i].y + env->yvar), COLOR);
		if (i > 0 && env->pt2d[i].line == env->pt2d[i - 1].line)
		{
			ft_draw(env->pt2d[i - 1], env->pt2d[i], env);
			ft_draw(env->pt2d[i], env->pt2d[i - 1], env);
		}
		if (env->pt2d[i].stay_high != NULL)
			ft_draw(env->pt2d[i], env->pt2d[i].stay_high[0], env);
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img_ptr, 0, 0);
	return ;
}
