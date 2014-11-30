/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:52:16 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/30 18:52:36 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
//	void	*mlx;
//	void	*win;
	t_map	map;

	map = NULL;
	if (ac != 2)
		write(1, "ERROR: Invalide arguments\n", 30);
	else
	{
//		write(1, "1\n", 2);
		map = ft_get_the_map(open(av[1], O_RDONLY), map);
//		mlx = mlx_init();
//		ft_putnbr(map->intline[0]);
	}
	if (map->intline[0] == 7)
		return (1);
	return (0);
}
