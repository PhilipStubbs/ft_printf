/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:10:05 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/14 10:37:23 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		findwild(char *str, int i)
{
	i++;
	while (str[i])
	{
		if (str[i] == '*')
			return (i);
		i++;
	}
	return (i);
}

int		istherespace(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	wildcard(t_printf *node, t_format *format, va_list args)
{
	int	*hold;
	int	nbr;
	int	i;
	int	space;

	hold = (int*)ft_memalloc(sizeof(int) * format->wild + 1);
	nbr = 0;
	while (nbr < format->wild)
	{
		i = va_arg(args, int);
		if (i >= 0)
			hold[nbr] = i;
		nbr++;
	}
	space = istherespace(node->raw);
	nbr = 0;
	i = format->start;
	while (nbr < format->wild)
	{
		if (node->raw[i - 1] == '.')
		{
			format->precsize = hold[nbr];
			nbr++;
		}
		if (ft_isdigit(node->raw[i - 1]) == 1 || node->raw[i - 1] == ' ' || ft_isdigit(node->raw[i + 1]) == 1 || ft_isalpha(node->raw[i + 1]) == 1)
		{
			if (space == 0 && hold[nbr] == 0)
				format->spacpad = 0;
			if (ft_isdigit(node->raw[i + 1]) == 0)
				format->padsize = hold[nbr];
			nbr++;
		}
		if (format->spacpad == 0 && format->zeropad == 0 && format->padsize != 0)
			format->spacpad = 1;
		i = findwild(node->raw, i);
		if (node->raw[i] == '\0')
			break;
	}
	// printf("start[%d] end[%d] spacpad[%d] zeropad[%d] padsize[%d] hash[%d] minus[%d] plus[%d] prec[%d] precpad[%d]\n",format->start,format->end, format->spacpad, format->zeropad,format->padsize ,format->hash,format->minus ,format->plus,format->prec, format->precsize);
	free(hold);
}

// ft_printf("M|%*d\n", 5, 42);