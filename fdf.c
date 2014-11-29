/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:52:16 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/29 15:40:37 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
//	void	*mlx;
//	void	*win;
	t_map	map;

	if (ac != 2)
		write(1, "ERROR: Invalide arguments\n", 30);
	else
	{
		write(1, "1\n", 2);
		map = ft_get_the_map(open(av[1], O_RDONLY));
//		mlx = mlx_init();
		ft_putnbr(map->intline[0]);
	}
	return (0);
}
