/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:31:05 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/27 19:46:31 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include "./libft/libft.h"

typedef struct s_map	t_line;

struct					s_line
{
	int					*intline;
	s_map				*nxt;
	s_map				*pvs;
};

typedef t_line			*t_map;

int						ft_get_the_map(int fd, int **map);

#endif
