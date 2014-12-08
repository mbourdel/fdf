/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_the_taff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:03:51 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/08 14:12:31 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void		ft_draw_line(t_ls2d pt2d, const t_env *env, int i, int color)
{
	int		dx;
	int		dy;
	int		e;
	if (i == 0)
		return;
	e = pt2d[i].x - pt2d[i - 1].x;
	dx = e * 2;
	dy = (pt2d[i].y - pt2d[i - 1].y) * 2;
	while (pt2d[i - 1].x <= pt2d[i].x && pt2d[i].memz == pt2d[i - 1].memz)
	{
		if (color == 1)
			mlx_pixel_put(env->mlx, env->win, pt2d[i - 1].x, pt2d[i - 1].y, ((WHITE - ((pt2d[i].memz) * 1000))));
		else
			mlx_pixel_put(env->mlx, env->win, pt2d[i - 1].x, pt2d[i - 1].y, ((WHITE - ((pt2d[i].memz) * 1000))));
		pt2d[i - 1].x = pt2d[i - 1].x + 1;
		if ((e = (e -dy)) <= 0)
		{
			pt2d[i - 1].y = pt2d[i - 1].y + 1;
			e = e + dx;
		}
	}
	return;
}
static void		ft_draw_pt2d(t_ls2d pt2d, const t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	while (pt2d[i].x != 0)
	{
		if (/*(pt2d[i].y != pt2d[i - j].y) && */(pt2d[i].x != XBEGIN) && pt2d[i].memz != 0)
		{
			mlx_pixel_put(env->mlx, env->win, pt2d[i].x, pt2d[i].y, (WHITE - ((pt2d[i].memz) * 1000)));
//			mlx_pixel_put(env->mlx, env->win, pt2d[i].x + 1, pt2d[i].y, (WHITE - ((pt2d[i - j].y) * 1000)));
//			mlx_pixel_put(env->mlx, env->win, pt2d[i].x, pt2d[i].y + 1, (WHITE - ((pt2d[i - j].y) * 1000)));
//			mlx_pixel_put(env->mlx, env->win, pt2d[i].x + 1, pt2d[i].y + 1, (WHITE - ((pt2d[i - j].y) * 1000)));
			if (pt2d[i].memz == pt2d[i - 1].memz)
				ft_draw_line(pt2d, env, i, 1);
			i++;
			j++;
		}
		else
		{
			j = 1;
			mlx_pixel_put(env->mlx, env->win, pt2d[i].x, pt2d[i].y, (WHITE - ((pt2d[i].memz) * 1000)));
//			mlx_pixel_put(env->mlx, env->win, pt2d[i].x + 1, pt2d[i].y, (WHITE - ((pt2d[i].y) * 1000)));
//			mlx_pixel_put(env->mlx, env->win, pt2d[i].x, pt2d[i].y + 1, (WHITE - ((pt2d[i].y) * 1000)));
//			mlx_pixel_put(env->mlx, env->win, pt2d[i].x + 1, pt2d[i].y + 1, (WHITE - ((pt2d[i].y) * 1000)));
			if (pt2d[i].x != XBEGIN)
				ft_draw_line(pt2d, env, i, 0);
			i++;
		}
	}
	return;
}

void			ft_make_the_taff(const t_env *env)
{
	t_map		map;
	t_ls3d		pt3d;
	t_ls2d		pt2d;

	map = NULL;
	map = ft_get_the_map(env->fd, map);
	pt3d = ft_set_pt3d(map);
	pt2d = ft_set_pt2d(pt3d);
	close(env->fd);
	ft_draw_pt2d(pt2d, env);
	return;
}
