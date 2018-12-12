/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:37:00 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/12 14:32:32 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

unsigned long long	g_count;
typedef struct		g_stuct
{
	char			flag;
	int				width;
	int				size;
	int				precision;
} g_data;
g_data		g_flags;
int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
int		intlen(int n);
int		check_width(const char *str);
void	struct_to_nul(void);
#endif
