/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:10:05 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/14 12:12:05 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		findwild(char *str, int i)
{
	i++;
	if (str[i] == '\0')
		return (i);
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

void	checkforcorrectminus(t_format *format, char *str, int *hold, int i)
{
	int nbr;
	int	x;

	nbr = 0;
	x = i;
	x = findwild(str, x);
	// if (str[x] == '\0')
	// 	return ;
	
	while (nbr < format->wild)
	{
		if (hold[nbr] < 0 && str[x - 1] != '.')
		{
			format->minus = 1;
			hold[nbr] *= -1;
		}
		nbr++;
	}
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
		hold[nbr] = i;
		nbr++;
	}
	space = istherespace(node->raw);
	nbr = 0;
	i = format->start;
	checkforcorrectminus(format, node->raw, hold, i);
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
	if (format->precsize < 0 && format->c == 's')
		format->precsize *= -1;
	if (format->precsize < 0 && format->c != 's')
		format->precsize = 0;
	free(hold);
}
