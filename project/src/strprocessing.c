/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:29:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/10 10:15:53 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lengthspec(char *str, int i, t_format *format)
{
	if (str[i] == '-' && format != NULL)
		format->minus = 1;
	if (str[i] == '+' && format != NULL)
		format->plus = 1;
	if (format != NULL && (str[i] == 'h' && str[i + 1] == 'h'))
		format->hh = 1;
	if (format != NULL && (str[i] == 'h' && format->hh == 0))
		format->h = 1;
	if (format != NULL && (str[i] == 'l' && str[i + 1] == 'l'))
		format->ll = 1;
	if (format != NULL && (str[i] == 'l' && format->ll == 0))
		format->l = 1;
	if (format != NULL && (str[i] == 'j'))
		format->j = 1;
	if (format != NULL && (str[i] == 'z'))
		format->z = 1;
	if (format != NULL && (format->hh == 1 || format->h == 1 || format->ll == 1
	|| format->l == 1 || format->j == 1 || format->z == 1))
	{
		format->lenmod = 1;
	}
}

void	normalspec(char *str, int i, t_format *format)
{
	if (str[i] == '#' && format != NULL)
		format->hash = 1;
	if (format != NULL && (str[i] == ' ' && format->spacpad == 0))
	{
		if (ft_isdigit(str[i + 1]) == 1 && str[i + 1] != 0)
			format->padsize = ft_atoi(str + i);
		format->spacpad = 1;
	}
	if (format != NULL && (str[i] == '0' && format->zeropad == 0 &&
	ft_isdigit(str[i - 1]) == 0))
	{
		format->zeropad = 1;
		format->padsize = ft_atoi(str + i);
	}
	if (format != NULL && (ft_isdigit(str[i]) == 1 && format->zeropad == 0 &&
	format->spacpad == 0 && str[i - 1] != '.'))
	{
		format->spacpad = 1;
		format->padsize = ft_atoi(str + i);
	}
	if (format != NULL && (str[i] == '.'))
	{
		format->prec = 1;
		format->precsize = ft_atoi(str + i + 1);
	}
}

int		findspecifier(char *str, int i, t_format *format)
{
	int	count;

	count = 1;
	i++;
	if (format != NULL)
		format->start = i;
	while (isnormalflag(str, i) == 1)
	{
		normalspec(str, i, format);
		lengthspec(str, i, format);
		i++;
		count++;
	}
	count--;
	i--;
	while (str[i] == ' ')
	{
		count--;
		i--;
	}
	if (format != NULL)
	{
		if (isvaildflag(str, i) == 0)
		{
		format->end = i + 1;
		format->c = str[i + 1];
		format->badflag = 1;
		}
		else 
		{
		format->end = i;
		format->c = str[i];
		}
		// printf("start[%d] end[%d] spacpad[%d] zeropad[%d] padsize[%d] hash[%d] minus[%d] plus[%d] prec[%d] precpad[%d]\n",format->start,format->end, format->spacpad, format->zeropad,format->padsize ,format->hash,format->minus ,format->plus,format->prec, format->precsize);
	}
	return (count);
}

int		flagchecker(t_printf *node, char *str,  va_list args, int i)
{
	t_format	*format;
	int			l;

	format = cleanformat();
	// printf("going in[%d]\n",i);
	l = findspecifier(str, i, format);
	// if (str[i + l] == '%' && str[i] == '%')
	// {
	// 	dynamicstring(&(node)->output, "%");
	// 	free(format);
	// 	return (1);
	// }
	if (str[i + l] == 's')
	{
		i = findstring(node, args, format);
		free(format);
		return (i);
	}
	else if (str[i + l] == 'd' || str[i + l] == 'D' || str[i + l] == 'i')
	{
		i = finddigit(node, args, format);
		free(format);
		return (i);
	}
	else if (str[i + l] == 'c' || str[i + l] == 'C')
	{
		findchar(node, args, format);
		free(format);
		return (1);
	}
	else if (str[i + l] == 'x' || str[i + l] == 'X')
	{
		i = findhex(node, args, str[i + l], format);
		free(format);
		return (i);
	}
	else if (str[i + l] == 'o' || str[i + l] == 'O')
	{
		i = findoct(node, args, format);
		free(format);
		return (i);
	}
	else if (str[i + l] == 'p')
	{
		i = findpointer(node, args, format);
		free(format);
		return (i);
	}
	else if (str[i + l] == 'U' || str[i + l] == 'u')
	{
		i = findundigit(node, args, format);
		free(format);
		return (i);
	}
	i = handlenonvalid(node, format);
	free(format);
	// printf("going out[%d]\n",i);
	return (i + 1);
}

int		movei(char *str, int i)
{
	int l;

	l = findspecifier(str, i, NULL);
	if (isvaildflag(str,i + l ) == 0)
		return (i + l + 2);
	if (str[i + l] == '%')
		return (i + l + 1);
	return (i + l + 1);
}

int		strprocessing(t_printf *node, char *str, va_list args)
{
	int		i;

	i = 0;
	node->output = (char*)ft_memalloc(sizeof(char) * node->size + 1);
	while (str[i])
	{
		if (str[i] != '%')
		{
			node->output = dynamicchar(&(node)->output, str[i]);
		}
		if (str[i] == '%')
		{
			node->l += flagchecker(node, str, args, i);
			i = movei(str, i);
		}
		else
		{
			node->l++;
			i++;
		}
		// write(1,"X\n",2); 
		// printf("i:%d%c | l:%d%c insied[%s]\n",i,str[i], node->l,node->output[node->l] ,node->output );
	}
	return (0);
}






























// void	createpadding(t_printf *node, char *str, int i)
// {
// 	int		amount;
// 	int		x;
// 	char	*amstr;

// 	x = 0;
// 	while (ft_isdigit(str[i + x]) == 1)
// 		x++;
// 	amstr = ft_strsub(str + i, 0, x);
// 	amount = ft_atoi(amstr);
// 	free(amstr);
// 	amstr = (char*)ft_memalloc(sizeof(char) * amount + 1);
// 	ft_memset(amstr, '0', amount);
// 	dynamicstring(&(node)->output, amstr);
// 	free(amstr);
// }

// int		*findspecifier(char *str, int i)
// {
// 	int	count;
// 	int	modif;
// 	int *ret;

// 	ret = (int*)ft_memalloc(sizeof(int) * 2);
// 	count = 1;
// 	i++;
// 	modif = -1;
// 	while (str[i] == ' ' || str[i] == '-' || str[i] == '+' || str[i] == '#' || str[i] == '0')
// 	{
// 		if ((str[i] == '-' || str[i] == '+' || str[i] == '#') && modif == -1)
// 		{
// 			modif = i;
// 		}
// 		if (str[i] == '0')
// 		{
// 			while (ft_isdigit(str[i]) == 1)
// 				i++;
// 		}
// 			// createpadding(node, str, i);
// 		i++;
// 		count++;
// 	}
// 	ret[0] = count;
// 	ret[1] = modif;
// 	return (ret);
// }

// int		flagchecker(t_printf *node, char *str,  va_list args, int i)
// {
// 	int	l;
// 	int	*f;

// 	f = findspecifier(str, i);
// 	l = f[0];
// 	printf("[%c ]\n",str[i + l]);
// 	if (str[i + l] == '%')
// 	{
// 		dynamicstring(&(node)->output, "%");
// 		return (1);
// 	}
// 	else if (str[i + l] == 's')
// 	{
// 		i = findstring(node, args);
// 		return (i);
// 	}
// 	else if (str[i + l] == 'd' || str[i + l] == 'D' || str[i + l] == 'i')
// 	{
// 		i = finddigit(node, args, l);
// 		return (i);
// 	}
// 	else if (str[i + l] == 'c' || str[i + l] == 'C')
// 	{
// 		findchar(node, args);
// 		return (1);
// 	}
// 	else if (str[i + l] == 'x' || str[i + l] == 'X')
// 	{
// 		i = findhex(node, args, str[i + l], f[1]);
// 		return (i);
// 	}
// 	else if (str[i + l] == 'o' || str[i + l] == 'O')
// 	{
// 		i = findoct(node, args, f[1]);
// 		return (i);
// 	}
// 	else if (str[i + l] == 'p')
// 	{
// 		i = findpointer(node, args);
// 		return (i);
// 	}
// 	else if (str[i + l] == 'U' || str[i + l] == 'u')
// 	{
// 		i = findundigit(node, args);
// 		return (i);
// 	}
// 	return (-1);
// }

// int		movei(char *str, int i)
// {
// 	int l;
// 	int	*f;

// 	f = findspecifier(str, i);
// 	l = f[0];
// 	if (str[i + l] == '%')
// 		return (i + l + 1);
// 	// else if (str[i + l] == 's')
// 	// 	return (i + l + 1);
// 	// else if (str[i + l] == 'd' || str[i + l] == 'D' || str[i + l] == 'i')
// 	// 	return (i + l + 1);
// 	// else if (str[i + l] == 'c' || str[i + l] == 'C')
// 	// 	return (i + l + 1);
// 	// else if (str[i + l] == 'x' || str[i + l] == 'X')
// 	// 	return (i + l + 1);
// 	// else if (str[i + l] == 'o' || str[i + l] == 'O')
// 	// 	return (i + l + 1);
// 	// else if (str[i + l] == 'p')
// 	// 	return (i + l + 1);
// 	// else if (str[i + l] == 'u' || str[i + l] == 'U')
// 	// 	return (i + l + 1);
// 	return (i + l + 1);
// }

// int		strprocessing(t_printf *node, char *str, va_list args)
// {
// 	int		i;

// 	i = 0;
// 	node->output = (char*)ft_memalloc(sizeof(char) * node->size + 1);
// 	while (str[i])
// 	{
// 		if (str[i] != '%')
// 		{
// 			node->output = dynamicchar(&(node)->output, str[i]);
// 		}
// 		if (str[i] == '%')
// 		{
// 			if ((node->l += flagchecker(node, str, args, i)) <= 0)
// 				return (1);
// 			i = movei(str, i);
// 		}
// 		else
// 		{
// 			node->l++;
// 			i++;
// 		}
// 		// printf("i:%d%c | l:%d%c insied[%s]\n",i,str[i], node->l,node->output[node->l] ,node->output );
// 	}
// 	return (0);
// }
