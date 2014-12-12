/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_the_taff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:03:51 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/12 17:33:22 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_make_the_taff(const t_env *env)
{
	t_map		map;
	t_ls3d		pt3d;
	t_ls2d		pt2d;

	map = NULL;
	map = ft_get_the_map(env->fd, map);
	close(env->fd);
	return ;
}
