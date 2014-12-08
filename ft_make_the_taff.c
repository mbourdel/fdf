/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_the_taff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:03:51 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/08 18:15:06 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_line(t_ls2d pt2d, const t_env *env, int i)
{
	int		dx;
	int		dy;
	int		e;

	if (i == 0)
		return ;
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

static void		ft_draw_pt2d(t_ls2d pt2d, const t_env *env)
{
	int		i;

	i = 0;
	while (pt2d[i].x != 0)
	{
		mlx_pixel_put(env->mlx, env->win, pt2d[i].x, pt2d[i].y, COLOR);
		if (pt2d[i].memz == pt2d[i - 1].memz)
			ft_draw_line(pt2d, env, i);
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
