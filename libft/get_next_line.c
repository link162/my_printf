/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:54:28 by ybuhai            #+#    #+#             */
/*   Updated: 2018/11/23 16:25:20 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**is_already(int fd, t_lst **list)
{
	t_lst	*new;

	new = *list;
	if (new)
	{
		if (new->fd == fd)
			return (&(new->str));
		while (new->next)
		{
			if (new->next->fd == fd)
				return (&(new->next->str));
			new = new->next;
		}
		new->next = (t_lst *)malloc(sizeof(t_lst));
		new->next->fd = fd;
		new->next->str = NULL;
		new->next->next = NULL;
		return (&(new->next->str));
	}
	*list = (t_lst *)malloc(sizeof(t_lst));
	(*list)->fd = fd;
	(*list)->str = NULL;
	(*list)->next = NULL;
	return (&((*list)->str));
}

int		str_cut(char **line, char **str, int fd, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while ((*str)[j] != '\0' && (*str)[j] != '\n')
		j++;
	if ((*str)[j] == '\n')
	{
		*line = ft_strsub(*str, 0, j);
		tmp = ft_strdup(&((*str)[++j]));
		free(*str);
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(&tmp);
	}
	else if ((*str)[j] == '\0')
	{
		if (i == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*m;
	char			buff[BUFF_SIZE + 1];
	char			**str;
	static t_lst	*list;
	int				i;

	if (fd < 0 || !line)
		return (-1);
	str = is_already(fd, &list);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(*str))
			*str = ft_strnew(1);
		buff[i] = '\0';
		m = ft_strjoin(*str, buff);
		free(*str);
		*str = m;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (i < 0)
		return (-1);
	else if ((i == 0 && !(*str)) || **str == '\0')
		return (0);
	return (str_cut(line, str, fd, i));
}
