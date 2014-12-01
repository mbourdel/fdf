/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pt3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 19:07:09 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/01 19:46:22 by mbourdel         ###   ########.fr       */
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
	int			xyz[3];
	t_map		tmp;
	t_ls3d		point;
	int			i;

	point = (t_ls3d)malloc(sizeof(t_pt3d) * ft_nb_point(map));
	tmp = map;
	xyz[1] = YBEGIN;
	while (tmp != NULL)
	{
		xyz[0] = XBEGIN;
		i = 0;
		while (i < tmp->size)
		{
			
		}
	}

	return (point);
}
