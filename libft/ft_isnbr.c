/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 19:55:12 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/30 20:04:10 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnbr(char *c)
{
	while (*c)
	{
		if (!(ft_isdigit(*c)))
			return (0);
		c++;
	}
	return (1);
}
