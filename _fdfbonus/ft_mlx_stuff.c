/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 10:44:24 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/13 18:41:40 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit(0);
	if (env->fd == 0)
		return (0);
	if (keycode == 65363)
		env->value.xvar += 30;
	if (keycode == 65361)
		env->value.xvar -= 30;
	if (keycode == 65362)
		env->value.yvar -= 20;
	if (keycode == 65364)
		env->value.yvar += 20;
	if (keycode == 65451)
		env->value.height += 2;
	if (keycode == 65453)
		env->value.height -= 2;
	ft_map(env);
	ft_putendl(ft_itoa(keycode));
	ft_bzero(env->img.data, (XWIN_SIZE * YWIN_SIZE * (env->img.bpp / 8)));
	ft_draw_pt2d(env);
	return (0);
}

int		expose_hook(t_env *env)
{
	ft_bzero(env->img.data, (XWIN_SIZE * YWIN_SIZE * (env->img.bpp / 8)));
	ft_draw_pt2d(env);
	return (0);
}
