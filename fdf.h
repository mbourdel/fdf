/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:31:05 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/07 17:01:05 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "get_next_line.h"

# define XWIN_SIZE 2000
# define YWIN_SIZE 1200
# define SPACE 40
# define HEIGHT 10
# define XBEGIN 1
# define YBEGIN 400
# define CST 0.9
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define COLOR (WHITE - ((env->pt2d[i].memz) * 300))
# define BCLR (WHITE - (((origin.memz * 280))))
# define ACLR (WHITE - (origin.memz * 300))

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
** Struct content all elements of the image
*/
typedef struct s_img	t_img;
struct					s_img
{
	void				*img_ptr;
	char				*data;
	int					bpp;
	int					sizeline;
	int					endian;
};

/*
** Struct content the value require for define the pixel position
*/
typedef struct s_value	t_value;
struct					s_value
{
	int					space;
	int					xbegin;
	int					ybegin;
	int					height;
	int					cst;
};

/*
** Struct content each point on 3D (x,y,z)
*/
typedef struct s_pt3d	t_pt3d;
struct					s_pt3d
{
	int					x;
	int					y;
	int					z;
	int					line;
	t_pt3d				*stay_high;
};
typedef t_pt3d			*t_ls3d;

/*
** Struct content each point on 2D converted (X,Y)
*/
typedef struct s_pt2d	t_pt2d;
struct					s_pt2d
{
	int					x;
	int					y;
	int					line;
	int					memz;
	t_pt2d				*stay_high;
};
typedef t_pt2d			*t_ls2d;

/*
** Struct environment
*/
typedef struct s_env	t_env;
struct					s_env
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_value				value;
	int					fd;
	t_ls2d				pt2d;
	int					xvar;
	int					yvar;
};

/*
** Function pull the map from file and convert point 3D->2D
*/
t_map					ft_get_the_map(int fd, t_map map);
t_ls3d					ft_set_pt3d(t_map map);
t_ls2d					ft_set_pt2d(t_ls3d pt3d);
int						ft_map(t_env *env);

/*
** Function for the mlx
*/
int						key_hook(int keycode, t_env *env);
int						expose_hook(t_env *env);
int						loop_hook(t_env *env);
void					ft_img(t_env *env);

/*
** Function for draw line between to point
*/
void					ft_draw_cone(t_pt2d origin, t_pt2d arrival, t_env *env);
void					ft_draw_ctwo(t_pt2d origin, t_pt2d arrival, t_env *env);
void					ft_draw_cthree(t_pt2d origin, t_pt2d arrival, t_env *env);
void					ft_draw_cfour(t_pt2d origin, t_pt2d arrival, t_env *env);
void					ft_draw_cfive(t_pt2d origin, t_pt2d arrival, t_env *env);
void					ft_draw_csix(t_pt2d origin, t_pt2d arrival, t_env *env);
void					ft_draw_cseven(t_pt2d origin, t_pt2d arrival, t_env *env);
void					ft_draw_ceight(t_pt2d origin, t_pt2d arrival, t_env *env);

/*
** Function "make_the_taff" call all function on the expose
*/
void					ft_draw_pt2d(t_env *env);
void					ft_draw(t_pt2d origin, t_pt2d arrival, t_env *env);

/*
** Function for draw on the screen
*/
void					ft_pixel_put_img(t_env *env, int x, int y, unsigned int color);

/*
** Function for choose the good color :)
*/
unsigned int			ft_color(t_pt2d point);

#endif
