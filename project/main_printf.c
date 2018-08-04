/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:27:25 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/04 12:50:58 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int			ft_printf(char *str, ...)
{
	t_printf	*node;
	va_list		args;
	int			error;
	int			ret;

	error = 0;
	ret = 0;
	node = createstruc();
	va_start(args, str);
	node->size = ft_strlen(str);
	error = strprocessing(node, str, args);
	va_end(args);
	if (error == 0)
	{
		ft_putstr(node->output);
		ret = ft_strlen(node->output);
	}
	destroy(&node, error);
	return (ret);
}
int main()
{
	// int i;
	// printf("[Hello %qd ", 123);
	// ft_printf("[Hello %d|%d|%d|%d|%d|%d|%d|%d|%d  |%d ] \n", 123, 4872, 34, 7647787, 4535, 75667, 45377, 75438, 9354, 10);
	// ft_printf("[Hello %s] \n", "this is going to be one massive string, likke a huge one, a very long long long l ong one!");
	// ft_printf("[%C%c%s]\n", 'c', 'a' , "HELKLO");
	// ft_printf("[Hello %s %x HELLO] \n", "this is going", 56498);
	// printf("[Hello %s %x HELLO] \n", "this is going", 56498);
	// printf("[Hello %s %O %c %C HELLO] \n", "this is going", 56498, 'a', 'a');
	// ft_printf("[Hello %s %O %c %C HELLO] \n", "this is going", 56498, 'a', 'a');
	// ft_printf("%s", ft_itoa_base(15, 16));
	// ft_printf("hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng hello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsdfg jnsdfkljgnkljn sdfkljng kljdsdnfghello iodfigndfgoinp niopsd\n");
	


	
	return (1);
}