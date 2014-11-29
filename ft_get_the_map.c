/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_the_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:34:20 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/29 17:52:47 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	ft_put_on_link(int *tab, t_map map, int size)
{
	t_map		new_link;
	int			i;

	i = 0;
	ft_putstr("ft_put_on_link:a\n");
	new_link = (t_map)malloc(sizeof(t_line));
	new_link->intline = malloc(sizeof(int) * size);
	while (i < size)
	{
		ft_putnbr(i);
		write(1, "\n", 1);
		new_link->intline[i] = tab[i];
		i++;
	}
	i = 0;
	ft_putstr("ft_put_on_link:YOLO\n");
	while (i < size)
	{
		ft_putnbr(new_link->intline[i++]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
	new_link->nxt = map;
	return (new_link);
}

static int		ft_get_int_line(int fd, int **line)
{
	char		*str;
	char		**split;
	int			i;

	ft_putstr("ft_get_int_line:c\n");
	i = 0;
	if (get_next_line(fd, &str) < 0)
		return (0);
	ft_putstr(str);
	write(1, "\n", 1);
	ft_putstr("ft_get_int_line:3\n");
	split = ft_strsplit(str, ' ');
	line[0] = malloc(sizeof(int));
	ft_putstr("ft_get_int_line:split\n");
	while (split[i] != '\0')
	{
	//	ft_putstr(split[i]);
	//	ft_putnbr(i);
		ft_putchar('\n');
		line[0] = ft_realloc(line[0], i);
		line[0][i] = ft_atoi(split[i]);
		ft_putnbr(line[0][i]);
		free(split[i]);
		i++;
	}
	ft_putstr("ft_get_int_line:wesh\n");
	free(split);
	return (i);
}

t_map			ft_get_the_map(int fd)
{
	t_map		map;
	int			*line;
	int			size;
	int			i;

	map = NULL;
	size = 1;
	ft_putstr("ft_get_map:2\n");
	while (size > 0)
	{
		size = ft_get_int_line(fd, &line);
		i = 0;
		ft_putstr("line\n-----\n");
		while (i < size)
		{
			ft_putnbr(line[i++]);
			ft_putchar(' ');
		}
		map = ft_put_on_link(line, map, size);
		free(line);
	}
	return (map);
}
