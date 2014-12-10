/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pt2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 19:08:54 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/10 15:05:14 by mbourdel         ###   ########.fr       */
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

static t_ls2d	ft_stay_high(int i, t_ls3d pt3d)
{
	t_ls2d		stay_high;

	stay_high = (t_ls2d)malloc(sizeof(t_pt2d));
	if (pt3d[i].stay_high == NULL)
		return (NULL);
	stay_high->x = (((pt3d[i].stay_high->x + (CST * pt3d[i].stay_high->z))));
	stay_high->y = (-pt3d[i].stay_high->y + ((CST / 2) * pt3d[i].stay_high->z));
	stay_high->memz = pt3d[i].stay_high->y;
	return (stay_high);
}

t_ls2d			ft_set_pt2d(t_ls3d pt3d)
{
	t_ls2d		point;
	int			i;

	i = 0;
	point = (t_ls2d)malloc(sizeof(t_pt2d) * (ft_nb_point(pt3d) + 1));
	while (pt3d[i].x)
	{
		point[i].x = (((pt3d[i].x + (CST * pt3d[i].z))));
		point[i].y = (-pt3d[i].y + ((CST / 2) * pt3d[i].z));
		point[i].memz = pt3d[i].y;
		point[i].stay_high = ft_stay_high(i, pt3d);
		if (point[i].stay_high != NULL)
		{
			ft_putstr("X-Y of   ");
			ft_putnbr(i);
			ft_putstr("  alt:  ");
			ft_putnbr(point[i].stay_high->memz);
			ft_putchar('\n');
			ft_putnbr(point[i].stay_high->x);
			ft_putchar('-');
			ft_putnbr(point[i].stay_high->y);
			ft_putchar('\n');
		}
		i++;
	}
	return (point);
}
