/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:45:46 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 10:45:51 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int		is_command(char *line)
{
	char **ret;

	if (line[0] == '#' && line[1] == '#')
	{
		ret = ft_split_whitespaces(line);
		if (ft_strstr(ret[0], "start") || ft_strstr(ret[0], "end"))
		{
			ft_strsplitdel(ret);
			return (0);
		}
		else
		{
			ft_strsplitdel(ret);
			return (1);
		}
	}
	return (0);
}

int		is_wrap_end(char *line, int *is_end)
{
	char **ret;

	if (line[0] == '#' && line[1] == '#')
	{
		ret = ft_split_whitespaces(line);
		if (ft_strstr(ret[0], "end"))
		{
			*is_end = 1;
			ft_strsplitdel(ret);
			return (1);
		}
		else
		{
			ft_strsplitdel(ret);
			return (0);
		}
	}
	return (0);
}

int		is_wrap_start(char *line, int *is_start)
{
	char **ret;

	if (line[0] == '#' && line[1] == '#')
	{
		ret = ft_split_whitespaces(line);
		if (ft_strstr(ret[0], "start"))
		{
			*is_start = 1;
			ft_strsplitdel(ret);
			return (1);
		}
		else
		{
			ft_strsplitdel(ret);
			return (0);
		}
	}
	return (0);
}
