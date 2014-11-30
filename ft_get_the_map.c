/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_the_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 21:34:20 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/30 20:47:54 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	ft_put_on_link(int *tab, t_map map, int size)
{
	t_map		new_link;
	int			i;

	i = 0;
	new_link = (t_map)malloc(sizeof(t_line));
	new_link->intline = malloc(sizeof(int) * size);
	while (i < size)
	{
		new_link->intline[i] = tab[i];
		i++;
	}
	new_link->nxt = map;
	return (new_link);
}

static int		*ft_get_int_line(int fd, int *line, int *size)
{
	char		*str;
	char		**split;
	int			i;

	*size = 1;
	if (get_next_line(fd, &str) <= 0)
		return (0);
	ft_putstr("\nresGNL:\n");
	ft_putstr(str);
	split = ft_strsplit(str, ' ');
	ft_putstr("\nget_line->split\n");
	while (split[*size - 1][0])
	{
		ft_putstr(split[*size]);
		ft_putchar(' ');
		*size = *size + 1;
	}
	ft_putstr(" xXx ");
	line = malloc(sizeof(int) * *size);
	ft_putstr(" xXx ");
	i = 0;
	while (i < *size)
	{
		line[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	i = 0;
	ft_putstr("\nget_line->line\n");
	while (i < *size)
	{
		ft_putnbr(line[i++]);
		ft_putchar(' ');
	}
	free(split);
	return (line);
}

t_map			ft_get_the_map(int fd, t_map map)
{
	int			*line;
	int			size;
	int			i;
	int			prout;

	prout = 0;
	size = 1;
	while (size > 0)
	{
		line = ft_get_int_line(fd, line, &size);
		prout++;
		i = 0;
		ft_putstr("\nget_map->line\n");
		ft_putnbr(prout);
		ft_putchar('\n');
		while (i < size)
		{
			ft_putnbr(line[i++]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		if (size > 0)
			map = ft_put_on_link(line, map, size);
		free(line);
	}
	ft_putnbr(prout);
	return (map);
}
