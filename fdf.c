/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:52:16 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/04 19:14:29 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env		env;
	t_map		map;
	t_ls3d		point;
	int			i;

	i = 0;
	map = NULL;
	if (ac != 2)
	{
		write(1, "ERROR: Invalide arguments\n", 30);
		return (1);
	}
	map = ft_get_the_map(open(av[1], O_RDONLY), map);
	ft_putstr("yolooo\n");
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 500, 500, "YOLOOO");
	point = ft_set_pt3d(map);
//	ft_putnbr(point[30].x);
//	ft_putstr(":");
//	ft_putnbr(point[30].y);
//	ft_putstr("\n");
//	mlx_string_put(env.mlx, env.win, 30, 30, RED, "yolooo");
	while (point[i].x != 0)
	{
//		ft_putnbr(i);write(1, "\n", 1);
//		mlx_pixel_put(env.mlx, env.win, i, i, RED);
		mlx_pixel_put(env.mlx, env.win, point[i].x, point[i].y, WHITE);
		mlx_pixel_put(env.mlx, env.win, point[i].x + 1, point[i].y, WHITE);
		mlx_pixel_put(env.mlx, env.win, point[i].x, point[i].y + 1, WHITE);
		mlx_pixel_put(env.mlx, env.win, point[i].x + 1, point[i].y + 1, WHITE);
		mlx_pixel_put(env.mlx, env.win, point[i].x + 2, point[i].y + 1, WHITE);
		mlx_pixel_put(env.mlx, env.win, point[i].x + 1, point[i].y + 2, WHITE);
		mlx_pixel_put(env.mlx, env.win, point[i].x + 2, point[i].y + 2, WHITE);
		i++;
	}
	sleep(10);
	return (0);
}
