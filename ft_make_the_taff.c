/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_the_taff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:03:51 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/10 18:48:46 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


//static void		ft_trace_segment(t_pt2d point,const t_env *env)
//{
//	if (point.stay_high == NULL)
//		return ;
//	mlx_pixel_put(env->mlx, env->win, point.stay_high->x, point.stay_high->y, RED);
//	return ;
//}

static void		ft_draw_flope(t_pt2d origin, t_pt2d arrival, const t_env *env)
{
	int		dx;
	int		dy;
	int		e;
	
	e = arrival.x - origin.x;
	dx = e * 2;
	dy = (arrival.y - origin.y) * 2;
	while (origin.x <= arrival.x)
	{
		mlx_pixel_put(env->mlx, env->win, origin.x, origin.y, RED);
		origin.x = origin.x + 1;
		if ((e = (e - dy)) <= 0)
		{
			origin.y = origin.y + 1;
			e = e + dx;
		}
	}
	return ;
}

static void		ft_draw_flope(t_pt2d origin, t_pt2d arrival, const t_env *env)
{
	int		dx;
	int		dy;
	int		e;
	
	e = arrival.x - origin.x;
	dx = e * 2;
	dy = (arrival.y - origin.y) * 2;
	while (origin.x <= arrival.x)
	{
		mlx_pixel_put(env->mlx, env->win, origin.x, origin.y, RED);
		origin.x = origin.x + 1;
		if ((e = (e - dy)) <= 0)
		{
			origin.y = origin.y + 1;
			e = e + dx;
		}
	}
	return ;
}

/*
static void		ft_draw_line(t_ls2d pt2d, const t_env *env, int i)
{
	int		dx;
	int		dy;
	int		e;

	e = pt2d[i].x - pt2d[i - 1].x;
	dx = e * 2;
	dy = (pt2d[i].y - pt2d[i - 1].y) * 2;
	while (pt2d[i - 1].x <= pt2d[i].x)
	{
		mlx_pixel_put(env->mlx, env->win, pt2d[i - 1].x, pt2d[i - 1].y, COLOR);
		pt2d[i - 1].x = pt2d[i - 1].x + 1;
		if ((e = (e - dy)) <= 0)
		{
			pt2d[i - 1].y = pt2d[i - 1].y + 1;
			e = e + dx;
		}
	}
	return ;
}
*/
/*
static void		ft_draw_slope(t_ls2d pt2d, const t_env *env, int i)
{
	int		dx;
	int		dy;
	float	x_by_y;
	int		a;
	int		b;

	if (i == 0)
		return ;
	b = 0;
	dx = abs(pt2d[i].x - pt2d[i - 1].x);
	dy = abs(pt2d[i].y - pt2d[i - 1].y);
	x_by_y = (dx / dy) ? (dx / dy) : (dy / dx);
	while (b < dx)
	{
		a = 0;
		pt2d[i - 1].y = pt2d[i - 1].y + 1;
		while (a < x_by_y)
		{
			pt2d[i - 1].x = pt2d[i - 1].x + 1;
			mlx_pixel_put(env->mlx, env->win, pt2d[i - 1].x, pt2d[i - 1].y, RED);
			a++;
		}
		b++;
	}
	return ;
}
*/

static void		ft_draw_pt2d(t_ls2d pt2d, const t_env *env)
{
	int		i;

	i = 0;
	while (pt2d[i].x != 0)
	{
		mlx_pixel_put(env->mlx, env->win, pt2d[i].x, pt2d[i].y, COLOR);
		if (pt2d[i].memz == pt2d[i - 1].memz && i != 0)
		{
//			ft_draw_line(pt2d, env, i);
//			if (pt2d[i].stay_high != NULL)
				ft_draw_flope(pt2d[i - 1], pt2d[i], env);
		}
//		else if (pt2d[i].stay_high != NULL)
//			ft_draw_flope(pt2d[i].stay_high[0], pt2d[i], env);
//		ft_trace_segment(pt2d[i], env);
//		else
//			ft_draw_slope(pt2d, env, i);
		i++;
	}
	return ;
}

void			ft_make_the_taff(const t_env *env)
{
	t_map		map;
	t_ls3d		pt3d;
	t_ls2d		pt2d;

	map = NULL;
	map = ft_get_the_map(env->fd, map);
	close(env->fd);
	pt3d = ft_set_pt3d(map);
	pt2d = ft_set_pt2d(pt3d);
	ft_draw_pt2d(pt2d, env);
	return ;
}
