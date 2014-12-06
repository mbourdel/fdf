/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 10:44:24 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/06 12:29:18 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, const t_env *env)
{
	if (keycode == 65307)
		exit(0);
	if (env->fd == 0)
		return (0);
	return (0);
}

int		expose_hook(const t_env *env)
{
	ft_make_the_taff(env);
	return (0);
}
