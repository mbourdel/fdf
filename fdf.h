/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:31:05 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/04 18:06:20 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "get_next_line.h"
# define SPACE 15
# define XBEGIN 15
# define YBEGIN 15
# define WHITE 0xFFFFFF
# define RED 0xFF0000

typedef struct s_env	t_env;
struct					s_env
{
	void				*mlx;
	void				*win;
};

typedef struct s_line	t_line;
struct					s_line
{
	int					*intline;
	int					size;
	t_line				*nxt;
};
typedef t_line			*t_map;

typedef struct s_pt3d	t_pt3d;
struct					s_pt3d
{
	int					x;
	int					y;
	int					z;
};
typedef t_pt3d			*t_ls3d;

typedef struct s_pt2d	t_pt2d;
struct					s_pt2d
{
	int					x;
	int					y;
};
typedef t_pt2d			*t_ls2d;

t_map					ft_get_the_map(int fd, t_map map);
t_ls3d					ft_set_pt3d(t_map map);

#endif
