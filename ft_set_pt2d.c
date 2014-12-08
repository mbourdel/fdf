/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pt2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 19:08:54 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/08 14:01:55 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_nb_point(t_ls3d pt3d)
{
	int			nb;

	nb = 0;
	while (pt3d[nb].x)
		nb++;
	return (nb);
}

t_ls2d			ft_set_pt2d(t_ls3d pt3d)
{
	t_ls2d		point;
	int			i;
	
	i = 0;
	point = (t_ls2d)malloc(sizeof(t_pt2d) * (ft_nb_point(pt3d) + 1));
	while (pt3d[i].x)
	{
		point[i].x = (pt3d[i].x + (CST * pt3d[i].z));
		point[i].y = (-pt3d[i].y + ((CST / 2) * pt3d[i].z));
		point[i].memz = pt3d[i].y;
		i++;
	}
	return (point);
}
