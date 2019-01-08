/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:04:35 by ybuhai            #+#    #+#             */
/*   Updated: 2019/01/04 16:18:22 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		print_last_ptr(char *str, int nulls_before, int free_place)
{
	int			str_len;
	int			i;

	i = 0;
	str_len = ft_strlen(str);
	while (free_place > 0)
		ft_put_char(' ');
	while (i < 2)
		ft_put_char(str[i++]);
	i = 0;
	while (i++ < nulls_before)
		ft_put_char('0');
	i = 2;
	while (i < str_len)
		ft_put_char(str[i++]);

}

void		print_first_ptr(char *str, int nulls_before, int free_place)
{
	int			str_len;
	int			i;

	str_len = ft_strlen(str);
	i = 0;
	while (i < 2)
		ft_put_char(str[i++]);
	i = 0;
	while (i++ < nulls_before)
		ft_put_char('0');
	i = 2;
	while (i < str_len)
		ft_put_char(str[i++]);
	while (free_place--)
		ft_put_char(' ');
}

void		print_null(void)
{
	char		*str;
	int			i;
	
	i = 0;
	str = malloc(sizeof(char) * 7);
	str = "(null)";
	while (str[i])
		ft_put_char(str[i++]);
	free(str);
}

void			print_ptr(char *str)
{
	int			str_len;
	int			free_place;
	int			nulls_before;

	if (!str)
	{
		print_null();
		return ;
	}
	free_place = 0;
	str_len = ft_strlen(str);
	if (g_flags.precision > str_len - 2)
		nulls_before = g_flags.precision - str_len + 2;
	if (g_flags.width > str_len || g_flags.width > g_flags.precision + 2)
		free_place = str_len > g_flags.precision + 2 ?
			g_flags.width - str_len : g_flags.width - g_flags.precision - 2;
	if (g_flags.flag[0] == '-')
		print_first_ptr(str, nulls_before, free_place);
	else
		print_last_ptr(str, nulls_before, free_place);
}

void			print_char(int nbr)
{
	int			free_place;
	int			i;

	i = 0;
	free_place = 0;
	if (g_flags.width > 1)
		free_place = g_flags.width - 1;
	if (g_flags.flag[0] == '-')
	{
		ft_put_char(nbr);
		while (i++ < free_place)
			ft_put_char(' ');
	}
	else
	{
		while (i++ < free_place)
			ft_put_char(' ');
		ft_put_char(nbr);
	}
}

void		print_first_last(char *str, int lenght, int free_place)
{
	int			i;

	i = 0;
	if (g_flags.flag[0] == '-')
	{
		while (i < lenght)
			ft_put_char(str[i++]);
		while (free_place-- > 0)
			ft_put_char(' ');
	}
	else
	{
		while (free_place-- > 0)
			ft_put_char(' ');
		while (i < lenght)
			ft_put_char(str[i++]);
	}
}

void			print_str(char *str)
{
	int			str_len;
	int			free_place;
	int			lenght;

	if (!str)
	{
		print_null();
		return ;
	}
	free_place = 0;
	str_len = ft_strlen(str);
	lenght = str_len;
	if (g_flags.precision >= 0 && g_flags.precision < str_len)
		lenght = g_flags.precision;
	if (g_flags.width > str_len)
		free_place = g_flags.width - lenght;
	print_first_last(str, lenght, free_place);
}
