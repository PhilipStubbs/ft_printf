/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:10:05 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/13 18:45:15 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		findwild(char *str, int i)
{
	while (str[i] != '*')
	{
		i++;
	}
	return (i);
}

void	wildcard(t_printf *node, t_format *format, va_list args)
{
	int	*hold;
	int	nbr;
	int	i;

	hold = (int*)ft_memalloc(sizeof(int) * format->wild + 1);
	nbr = 0;
	while (nbr < format->wild)
	{
		i = va_arg(args, int);
		if (i >= 0)
			hold[nbr] = i;
		nbr++;
	}
	nbr = 0;
	i = format->start;
	while (nbr < format->wild)
	{
		i = findwild(node->raw, i + 1);
		if (node->raw[i - 1] == '.')
		{
			format->precsize = hold[nbr];
			nbr++;
		}
		if (ft_isdigit(node->raw[i - 1]) == 1 || node->raw[i - 1] == ' ')
		{
			format->padsize = hold[nbr];
			nbr++;
		}
	}
	free(hold);
}