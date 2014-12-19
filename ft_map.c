/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 14:03:58 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/19 14:14:38 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_map(t_env *env)
{
	t_map		map;
	t_ls3d		pt3d;

	map = NULL;
	map = ft_get_the_map(env->fd, map);
	if (map == NULL)
		return (1);
	pt3d = ft_set_pt3d(map);
	env->pt2d = ft_set_pt2d(pt3d);
	return (0);
}
