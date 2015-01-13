/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_pt2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 17:07:14 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/07 17:18:01 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_edit_zoom(t_env *env)
{
	int		i;

	i = 0;
	while (env->pt2d[i].x)
	{
		env->pt2d[i].x = env->pt2d[i].x * env->value.space;
		env->pt2d[i].y = env->pt2d[i].y * env->value.space;
		env->pt2d[i].stay_high = 
	}
	return ;
}

void			ft_edit_pt2d(t_env *env, int modif)
{
	if (modif == 1)
		kdjfnfd;
	if (modif == 2)
		ksjfn;
	if (modif == 3)
		isndfioun;
	return ;
}
