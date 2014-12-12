/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_the_taff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:03:51 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/12 18:26:21 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_line(t_pt2d origin, t_pt2d arrival, const t_env *env)
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

static void		ft_draw_slope(t_pt2d origin, t_pt2d arrival, const t_env *env)
{
	int		dx;
	int		dy;
	int		e;
	
	e = arrival.y - origin.y;
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


static void		ft_draw_pt2d(t_ls2d pt2d, const t_env *env)
{
	int		i;

	i = 0;
	while (pt2d[i].x != 0)
	{
		mlx_pixel_put(env->mlx, env->win, pt2d[i].x, pt2d[i].y, COLOR);
		if (pt2d[i].memz == pt2d[i - 1].memz && i != 0)
		{
			ft_draw_line(pt2d[i - 1], pt2d[i], env);
			if (pt2d[i].stay_high != NULL)
			{
				if (pt2d[i].stay_high->memz != pt2d[i].memz)
					ft_draw_slope(pt2d[i].stay_high[0], pt2d[i - 1], env);
				else
				{
					ft_draw_line(pt2d[i].stay_high[0], pt2d[i], env);
					ft_draw_slope(pt2d[i - 1], pt2d[i].stay_high[0], env);
				}
			}
		}
		else if (i != 0)
		{
			ft_draw_line(pt2d[i], pt2d[i - 1], env);
			if (pt2d[i].stay_high != NULL)
			{
				if (pt2d[i].stay_high->memz != pt2d[i].memz)
					ft_draw_slope(pt2d[i], pt2d[i].stay_high[0], env);
				else
					ft_draw_line(pt2d[i].stay_high[0], pt2d[i], env);
			}
		}
//		if (pt2d[i].stay_high != NULL)
//		{
//			if (pt2d[i].stay_high->memz != pt2d[i].memz)
//				ft_draw_slope(pt2d[i].stay_high[0], pt2d[i], env);
//			else
//			{
//				ft_draw_line(pt2d[i].stay_high[0], pt2d[i], env);
//				ft_draw_slope(pt2d[i], pt2d[i].stay_high[0], env);
//			}
//		}

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
