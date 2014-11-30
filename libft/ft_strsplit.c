/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:06:24 by mbourdel          #+#    #+#             */
/*   Updated: 2014/11/30 20:42:08 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_split(char **ret, char *str, char c)
{
	int		i;
	int		j;
	int		x;

	x = 0;
	i = 0;
	j = 0;
	while (str[x])
	{
		if (str[x] != c)
			ret[j][i++] = str[x++];
		else if (str[x - 1] != c && ret[j][0] != '\0')
		{
			x++;
			i = 0;
			j++;
		}
		else
			x++;
	}
	ret[j][0] = '\0';
	return (ret);
}

char			**ft_strsplit(const char *s, char c)
{
	char	*str;
	char	**ret;
	int		nbofstr;
	int		i;

	if (!*s)
		return (NULL);
	str = (char*)s;
	i = 0;
	nbofstr = 0;
	if (str[i] != c)
		nbofstr++;
	while (str[++i])
		if (str[i] == c && str[i + 1] != c)
			nbofstr++;
	i = 0;
	ret = (char**)malloc(sizeof(char*) * nbofstr);
	while (i < nbofstr)
		ret[i++] = (char*)ft_memalloc(ft_strlen(str));
	return (ft_split(ret, str, c));
}
