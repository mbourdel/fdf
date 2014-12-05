/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:52:16 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/05 19:59:24 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env		env;
	t_map		map;
	t_ls3d		point;
	t_ls2d		pt2d;
	int			i;

	i = 0;
	map = NULL;
	if (ac != 2)
	{
		write(1, "ERROR: Invalide arguments\n", 30);
		return (1);
	}
	map = ft_get_the_map(open(av[1], O_RDONLY), map);
//	ft_putstr("yolooo\n");
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 500, 500, "YOLOOO");
	point = ft_set_pt3d(map);
	pt2d = ft_set_pt2d(point);
//	ft_putnbr(point[30].x);
//	ft_putstr(":");
//	ft_putnbr(point[30].y);
//	ft_putstr("\n");
//	mlx_string_put(env.mlx, env.win, 30, 30, RED, "yolooo");
//
	while (pt2d[i].x != 0)
	{
//		ft_putnbr(i);write(1, "\n", 1);
//		mlx_pixel_put(env.mlx, env.win, i, i, RED);
//		if (pt2d[i].y > pt2d[i - 1].y)
//			mlx_pixel_put(env.mlx, env.win, pt2d[i].x, pt2d[i].y, RED);
//		else
			mlx_pixel_put(env.mlx, env.win, pt2d[i].x, pt2d[i].y, WHITE);
//		mlx_pixel_put(env.mlx, env.win, pt2d[i].x + 1, pt2d[i].y, WHITE);
//		mlx_pixel_put(env.mlx, env.win, pt2d[i].x, pt2d[i].y + 1, WHITE);
//		mlx_pixel_put(env.mlx, env.win, pt2d[i].x + 1, pt2d[i].y + 1, WHITE);
//		mlx_pixel_put(env.mlx, env.win, pt2d[i].x + 2, pt2d[i].y + 1, WHITE);
//		mlx_pixel_put(env.mlx, env.win, pt2d[i].x + 1, pt2d[i].y + 2, WHITE);
//		mlx_pixel_put(env.mlx, env.win, pt2d[i].x + 2, pt2d[i].y + 2, WHITE);
		i++;
	}
	sleep(10);
	return (0);
}
