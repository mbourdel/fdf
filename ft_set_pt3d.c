/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pt3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 19:07:09 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/08 15:48:41 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_nb_point(t_map map)
{
	int		nb;

	nb = 0;
	while (map != NULL)
	{
		nb += (map->size + 1);
		map = map->nxt;
	}
	return (nb);
}

t_ls3d			ft_set_pt3d(t_map map)
{
	int			xyz[2];
	t_ls3d		point;
	int			i;
	int			j;

	j = 0;
	point = (t_ls3d)malloc(sizeof(t_pt3d) * (ft_nb_point(map) + 1));
	xyz[1] = YBEGIN;
	while (map != NULL)
	{
		xyz[0] = XBEGIN;
		i = 0;
		while (i < map->size)
		{
			point[j].x = xyz[0];
			point[j].z = xyz[1];
			point[j++].y = map->intline[i++] * HEIGHT;
			xyz[0] += SPACE;
		}
		xyz[1] += SPACE;
		map = map->nxt;
	}
	point[++j].x = 0;
	return (point);
}
