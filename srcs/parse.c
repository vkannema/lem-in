/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:53:43 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 11:23:06 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_ant(t_data *d)
{
	char	*line;
	int		i;

	i = 0;
	if (!get_next_line(0, &line))
	{
		ft_fatal(4);
		return ;
	}
	d->ants = ft_atoi(line);
	while (line[i])
	{
		if (!ft_isdigit_str(line) || d->ants <= 0)
			ft_fatal(ERROR_ANTS);
		i++;
	}
	ft_putendl(line);
	ft_strdel(&line);
}

void	save_room(t_data *d, char **room, int *is_start, int *is_end)
{
	d->name[d->rooms] = ft_strdup(room[0]);
	ft_strsplitdel(room);
	if (*is_start == 1)
	{
		d->start = d->rooms;
		*is_start = 0;
	}
	if (*is_end == 1)
	{
		d->end = d->rooms;
		*is_end = 0;
	}
	d->rooms++;
}

char	**is_room(char *line)
{
	char	**ret;
	int		len;

	len = 0;
	ret = ft_split_whitespaces(line);
	while (ret[len] != NULL)
		len++;
	if (len != 3)
	{
		ft_strsplitdel(ret);
		return (NULL);
	}
	if (ret[0][0] == 'L' || ret[0][0] == '#' || !ft_isdigit_str(ret[1])
						|| !ft_isdigit_str(ret[2]))
	{
		ft_strsplitdel(ret);
		ft_fatal(7);
	}
	return (ret);
}

char	*parse_room(t_data *d)
{
	char	*line;
	char	**room;
	int		is_start;
	int		is_end;

	is_start = 0;
	is_end = 0;
	while (get_next_line(0, &line) && !ft_strchr(line, '-'))
	{
		ft_putendl(line);
		if (is_wrap_start(line, &is_start) || is_wrap_end(line, &is_end))
			;
		else if ((room = is_room(line)))
			save_room(d, room, &is_start, &is_end);
		ft_strdel(&line);
	}
	return (line);
}

void	parse(t_graph *g, t_data *d)
{
	char	*line;

	parse_ant(d);
	line = parse_room(d);
	error_room(d);
	alone_line(d, g, line);
	parse_edges(d, g);
	check_double_edge(d, g);
}
