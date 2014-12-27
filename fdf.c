/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:52:16 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/27 19:06:20 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_env		env;

	if (ac != 2)
	{
		ft_putstr("ERROR: invalid arguments\n");
		return (1);
	}
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, XWIN_SIZE, YWIN_SIZE, av[1]);
	ft_img(&env);
	if ((env.fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr("ERROR: invalid arguments\n");
		return (1);
	}
	if (ft_map(&env))
	{
		ft_putendl("ERROR: invalid map");
		return (1);
	}
	close(env.fd);
	env.xvar = 0;
	ft_make_the_taff(&env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_expose_hook(env.mlx, expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
