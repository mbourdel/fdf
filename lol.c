/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 20:40:33 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/25 21:09:06 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	x = 125;
	y = 125;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 255, 255, "YOLOOOO");
//	while (y < 160)
//	{
//		while (x < 160)
//			mlx_pixel_put(mlx, win, x++, y, BLUE);
//		y++;
//		x = 125;
//	}
	mlx_string_put(mlx, win, x, y, RED,"YOLLOOOOOOO");
	sleep(5);
	return (0);
}
