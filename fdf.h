/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:31:05 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/30 18:49:54 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "get_next_line.h"

typedef struct s_line	t_line;

struct					s_line
{
	int					*intline;
	t_line				*nxt;
};

typedef t_line			*t_map;

t_map					ft_get_the_map(int fd, t_map map);

#endif
