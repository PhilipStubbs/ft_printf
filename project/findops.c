/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:48:41 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/06 13:39:52 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*createpadding(t_printf *node, char **str, int *f, char c)
{
	int		amount;
	int		x;
	int		len;
	char	*amstr;
	char	*tmp;

	x = 1;
	len = ft_strlen(*str);
	while (ft_isdigit(node->raw[f[3] + x]) == 1)
		x++;
	amstr = ft_strsub(node->raw + f[0], 1, x-1);
	printf("[%s]\n", amstr);
	amount = ft_atoi(amstr) - len;
	if (amount < len)
		return (*str);
	free(amstr);
	printf("[%d]\n",amount);
	// if (node->raw[f[2] + f[0]] == ' ')
	if (spacechecker(node->raw, f[2]) == 1)
	{
		tmp = ft_strdup(" ");

		amstr = ft_strnew(amount);
		write(1,"X\n",2); 
		ft_memset(amstr, '0', amount);
		
		amstr = dynamicstring(&amstr, tmp);
		free(tmp);
	}
	else
	{
		amstr = ft_strnew(amount);
		ft_memset(amstr, c, amount);
	}
	tmp = ft_strjoin(amstr, *str);
	free(*str);
	*str = ft_strdup(tmp);
	free(amstr);
	free(tmp);
	return (*str);
}


	// ret[1] = count;
	// ret[2] = modif;
	// ret[3] = padding;

int	findstring(t_printf *node, va_list args)
{
	char	*tmp;
	int		len;

	tmp = va_arg(args, char*);
	if (tmp == NULL)
		tmp = ft_strdup("(null)");
	len = ft_strlen(tmp);
	node->output = dynamicstring(&(node)->output, tmp);
	// free(tmp);
	return (len);
}

int	finddigit(t_printf *node, va_list args, int *f)
{
	int		tmp;
	int		len;
	char	*ret;

	tmp = va_arg(args, int);
	ret = ft_itoa(tmp);
	printf("here[%d]\n", f[2]);
	if (f[3] != -1 || spacechecker(node->raw, f[2]))
		ret = createpadding(node, &ret, f, node->raw[f[2]]);
	
	// if (node->raw[f[1]] == ' ')
	// {
	// 	retstr = ft_strjoin(" ", ret);
	// 	node->output = dynamicstring(&(node)->output, retstr);
	// 	free(retstr);
	// }
	// else
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	node->padding = -1;
	return (len);
}

int	findchar(t_printf *node, va_list args)
{
	char	tmp;

	tmp = va_arg(args, int);
	node->output = dynamicchar(&(node)->output, tmp);
	return (1);
}

int	findhex(t_printf *node, va_list args, char cap, int modif)
{
	int		tmp;
	char	*tmpstr;
	char	*tmpstr2;

	tmp = va_arg(args, int);
	if (cap == 'x')
		tmpstr = ft_itoa_base(tmp, 16, 0);
	else
		tmpstr = ft_itoa_base(tmp, 16, 1);
	if (node->raw[modif] == '#')
	{
		if (cap == 'X')
			tmpstr2 = ft_strjoin("0X", tmpstr);
		else
			tmpstr2 = ft_strjoin("0x", tmpstr);
		free(tmpstr);
		tmpstr = ft_strdup(tmpstr2);
		free(tmpstr2);
	}
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}

int	findoct(t_printf *node, va_list args, int modif)
{
	int		tmp;
	char	*tmpstr;
	char	*tmpstr2;

	tmp = va_arg(args, int);
	tmpstr = ft_itoa_base(tmp, 8, 0);
	if (node->raw[modif] == '#')
	{
		tmpstr2 = ft_strjoin("0", tmpstr);
		free(tmpstr);
		tmpstr = ft_strdup(tmpstr2);
		free(tmpstr2);
	}
	node->output = dynamicstring(&(node)->output, tmpstr);
	tmp = ft_strlen(tmpstr);
	free(tmpstr);
	return (tmp);
}

int	findpointer(t_printf *node, va_list args)
{
	unsigned long	tmp;
	char			*tmpstr;
	char			*ret;

	tmp = va_arg(args, unsigned long);
	tmpstr = ft_itoa_base(tmp, 16, 0);
	ret = ft_strjoin("0x", tmpstr);
	node->output = dynamicstring(&(node)->output, ret);
	tmp = ft_strlen(ret);
	free(tmpstr);
	free(ret);
	return (tmp);
}

int	findundigit(t_printf *node, va_list args)
{
	unsigned int	tmp;
	int				len;
	char			*ret;

	tmp = va_arg(args, unsigned int);
	ret = ft_uitoa(tmp);
	node->output = dynamicstring(&(node)->output, ret);
	len = ft_strlen(ret);
	free(ret);
	return (len);
}
// 	if (chr <= 0x7F)
// 		chr_len = 1;
// 	else if (chr <= 0x7FF)
// 		chr_len = 2;
// 	else if (chr <= 0xFFFF)
// 		chr_len = 3;
// 	else if (chr <= 0x10FFFF)
// 		chr_len = 4;
// 	else
// 		chr_len = 0;