/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 10:44:24 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/16 20:54:57 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit(0);
	if (env->fd == 0)
		return (0);
	if (keycode == 65361)
		env->wesh += 30;
	if (keycode == 65363)
		env->wesh -= 30;
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (env->wesh);
}

int		expose_hook(t_env *env)
{
	ft_make_the_taff(env);
	return (0);
}

/*int		loop_hook(t_env *env)
{
	mlx_expose_hook(env->win, expose_hook, (t_env*)env);
	ft_make_the_taff(env);
	return (0);
}*/
