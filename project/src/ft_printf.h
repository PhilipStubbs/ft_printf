/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:08:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/10 13:31:17 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
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

typedef	struct	s_format
{
	char		c;
	int			start;
	int			end;
	int			spacpad;
	int			zeropad;
	int			padsize;
	int			hash;
	int			minus;
	int			plus;
	int			prec;
	int			precsize;
	int			badflag;
	int			lenmod;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_format;

typedef	struct	s_printf
{
	char		*output;
	char		*raw;
	int			size;
	int			padding;
	int			swit;
	int			*nulls;
	int			l;
}				t_printf;

int				ft_printf(char *str, ...);
char			*dynamicstring(char **ori, char *add);
char			*dynamicchar(char **ori, char add);
t_printf		*createstruc(void);
t_format		*cleanformat(void);
void			destroy(t_printf **node, int error);
int				strprocessing(t_printf *node, char *str, va_list args);

int				findstring(t_printf *node, va_list args, t_format *format);
int				finddigit(t_printf *node, va_list args, t_format *format);
int				findchar(t_printf *node, va_list args, t_format *format);
int				findhex(t_printf *node, va_list args, char cap, t_format *fo);
int				findoct(t_printf *node, va_list args, t_format *format);
int				findpointer(t_printf *node, va_list args, t_format *format);
int				findundigit(t_printf *node, va_list args, t_format *format);
int				handlenonvalid(t_printf *node, t_format *format);
char			*createpadding(char **str, t_format *format);
int				isnormalflag(char *str, int i);
int				spacechecker(char *str, int l);
int				isvaildflag(char *str, int i);
char			*precision(t_format *format, char **str);
char			*lengthmoddig(t_format *format, long long num);
int				findundigit(t_printf *node, va_list args, t_format *format);
int				justpercent(t_printf *node, t_format *format);


char			*ft_itoa_base(long int value, int base, int cap);
char			*ft_uitoa(unsigned int n);
#endif
