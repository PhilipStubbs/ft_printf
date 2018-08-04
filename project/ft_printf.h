/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:08:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/04 16:52:36 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define ERROR ft_putendl_fd("Error", 2);
# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

#include <stdio.h>

typedef	struct	s_printf
{
	char		*output;
	int			size;
	int			l;
	int			s;
	int			S;
	int			p;
	int			d;
	int			i;
	int			o;
	int			u;
	int			x;
	int			c;
}				t_printf;

int				ft_printf(char *str, ...);
char			*dynamicstring(char **ori, char *add);
char			*dynamicchar(char **ori, char add);
t_printf		*createstruc(void);
void			destroy(t_printf **node, int error);
int				strprocessing(t_printf *node, char *str, va_list args);

int				findstring(t_printf *node, va_list args);
int				finddigit(t_printf *node, va_list args, int l);
int				findchar(t_printf *node, va_list args);
int				findhex(t_printf *node, va_list args, char cap);
int				findoct(t_printf *node, va_list args);
int				findpointer(t_printf *node, va_list args);
int				findundigit(t_printf *node, va_list args);
char			*ft_uitoa(unsigned int n);

char			*ft_itoa_base(long int value, int base, int cap);
#endif
