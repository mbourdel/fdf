/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:52:16 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/01 17:51:45 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_map	map;
//	int		i;

	map = NULL;
	if (ac != 2)
		write(1, "ERROR: Invalide arguments\n", 30);
	else
	{
		map = ft_get_the_map(open(av[1], O_RDONLY), map);
		mlx = mlx_init();
		win = mlx_new_window(mlx, 500, 500, "YOLOOO");
		mlx_pixel_put(mlx, win, 250, 250, RED);
	}
/*	while (map != NULL)
	{
		i = 0;
		while (i < map->size)
		{
			ft_putnbr(map->intline[i++]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		map = map->nxt;
	}	*/
	return (0);
}
