/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_the_taff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:03:51 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/19 12:11:39 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_line(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int		dx;
	int		dy;
	int		e;
	
	e = arrival.x - origin.x;
	dx = e * 2;
	dy = (arrival.y - origin.y) * 2;
	while (origin.x <= arrival.x)
	{
		mlx_pixel_put(env->mlx, env->win, origin.x, origin.y, ACLR);
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
	int		dx;
	int		dy;
	int		e;
	
	e = abs(arrival.y - origin.y);
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		mlx_pixel_put(env->mlx, env->win, origin.x, origin.y, BCLR);
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
	dx = (arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		mlx_pixel_put(env->mlx, env->win, origin.x, origin.y, BCLR);
		origin.y = origin.y + 1;
		if ((e = (e - dx)) <= 0)
		{
			origin.x = origin.x + 1;
			e = e + dy;
		}
	}
	return ;
}

static void		ft_choose_itself_like_a_big_boy(t_ls2d pt2d, int i,t_env *env)
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
/*	if (pt2d[i].memz == pt2d[i - 1].memz)
	{
		ft_draw_line(pt2d[i - 1], pt2d[i], env);
		if (pt2d[i].stay_high != NULL)
		{
			if (pt2d[i].stay_high->memz != pt2d[i].memz)
				ft_draw_slope(pt2d[i].stay_high[0], pt2d[i - 1], env);//
			else
				ft_draw_line(pt2d[i].stay_high[0], pt2d[i], env);
		}
	}
	else
	{
		ft_draw_line(pt2d[i], pt2d[i - 1], env);
		if (pt2d[i].stay_high != NULL)
		{
			if (pt2d[i].stay_high->memz != pt2d[i].memz)
				ft_draw_slope(pt2d[i], pt2d[i].stay_high[0], env);//
			else
				ft_draw_line(pt2d[i].stay_high[0], pt2d[i], env);
		}
	}
*/
	return ;
}

static void		ft_draw_pt2d(t_ls2d pt2d, t_env *env)
{
	int		i;

	i = 0;
	while (pt2d[i].x != 0)
	{
		mlx_pixel_put(env->mlx, env->win, pt2d[i].x, pt2d[i].y, COLOR);
		if (i > 0)
			ft_choose_itself_like_a_big_boy(pt2d, i,  env);
		i++;
	}
	return ;
}

void			ft_make_the_taff(t_env *env)
{
	t_map		map;
	t_ls3d		pt3d;
	t_ls2d		pt2d;

	map = NULL;
	map = ft_get_the_map(env->fd, map);
	pt3d = ft_set_pt3d(map);
	pt2d = ft_set_pt2d(pt3d);
	ft_draw_pt2d(pt2d, env);
	return ;
}
