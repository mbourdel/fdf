/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:31:05 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/11 19:19:49 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "get_next_line.h"

# define XWIN_SIZE 1000
# define YWIN_SIZE 500
# define SPACE 20
# define HEIGHT 10
# define XBEGIN 1
# define YBEGIN 400
# define CST 0.9
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define COLOR (WHITE - ((pt2d[i].memz) * 1000))
# define BCLR (WHITE - ((origin.memz * 1000) - (origin.y * 100)))
# define ACLR (WHITE - (origin.memz * 1000))

/*
** Struct environment
*/
typedef struct s_env	t_env;
struct					s_env
{
	void				*mlx;
	void				*win;
	int					fd;
};

/*
** Struct list content each line of the map as integer
*/
typedef struct s_line	t_line;
struct					s_line
{
	int					*intline;
	int					size;
	t_line				*nxt;
};
typedef t_line			*t_map;

/*
** Struct content each point on 3D (x,y,z)
*/
typedef struct s_pt3d	t_pt3d;
struct					s_pt3d
{
	int					x;
	int					y;
	int					z;
	t_pt3d				*stay_high;
};
typedef t_pt3d			*t_ls3d;

/*
** Struct content each point on 2D converted (X,Y)
*/
typedef struct s_pt2d	t_pt2d;
struct					s_pt2d
{
	float				x;
	float				y;
	int					memz;
	t_pt2d				*stay_high;
};
typedef t_pt2d			*t_ls2d;

/*
** Function pull the map from file and convert point 3D->2D
*/
t_map					ft_get_the_map(int fd, t_map map);
t_ls3d					ft_set_pt3d(t_map map);
t_ls2d					ft_set_pt2d(t_ls3d pt3d);

/*
** Function for the mlx
*/
int						key_hook(int keycode, const t_env *env);
int						expose_hook(const t_env *env);

/*
** Function "make_the_taff" call all function on the expose
*/
void					ft_make_the_taff(const t_env *env);

#endif
