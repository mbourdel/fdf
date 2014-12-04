/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:52:16 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/04 17:04:06 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_ls3d	point;
	int		i;

	i = 0;
	map = NULL;
	if (ac != 2)
	{
		write(1, "ERROR: Invalide arguments\n", 30);
		return (1);
	}
	map = ft_get_the_map(open(av[1], O_RDONLY), map);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "YOLOOO");
	point = ft_set_pt3d(map);
	while (point[i].x != 0)
	{
		ft_putnbr(i);write(1, "\n", 1);
		mlx_pixel_put(mlx, win, point[i].x, point[i].y, WHITE);
		mlx_pixel_put(mlx, win, point[i].x + 1, point[i].y, WHITE);
		mlx_pixel_put(mlx, win, point[i].x, point[i].y + 1, WHITE);
		mlx_pixel_put(mlx, win, point[i].x + 1, point[i].y + 1, WHITE);
		i++;
	}
	sleep(10);
	return (0);
}
