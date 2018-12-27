/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:37:00 by ybuhai            #+#    #+#             */
/*   Updated: 2018/12/27 17:38:08 by ybuhai           ###   ########.fr       */
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
	char			flag[5];
	int				width;
	int				length;
	int				precision;
	int				symbol;
} g_data;
g_data		g_flags;
int		ft_printf(const char *format, ...);
void	ft_putchar(int c);
int		intlen(__int128 n);
int		check_width(const char *str);
int		check_length(const char *str);
int		check_symbol(char c);
int		check_precision(const char *str);
void	prepare_to_print(va_list argptr);
void	print_char(int c);
void	print_str(char *str);
void	print_int(__int128 nbr);
void	struct_to_nul(void);
void	print_address_hex(void *p0);
void	print_ptr(char *str);
void	print_hex(__int128 nbr);
void	print_double(long double nbr);
size_t	ft_str_len(const char *str);

void	ft_bzero(void *destination, size_t n);

#endif
