/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_the_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:34:20 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/27 20:13:54 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_get_int_line(int fd, int **line)
{
	char	**str;
	char	**split;
	int		ret;
	int		i;

	i = 0;
	ret = get_next_line(fd, &str);
	split = ft_strsplit(str, ' ');
	line[0] = malloc(sizeof(int));
	while (split[i] != '\0')
	{
		line[0] = ft_realloc(i);
		line[0][i] = ft_atoi(split[i]);
		free(&split[i]);
		i++;
	}
	free(split);
	return (ret);
}

int				**ft_get_the_map(int fd)
{
	t_map	map;
	int		*line;
	int		end;

	map = NULL;
	end = 1;
	while (end == 1)
	{
		end = ft_get_int_line(fd, &line, &end);
		
	}
	return (map);
}
