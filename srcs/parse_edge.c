/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_edge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:23:40 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 10:44:37 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**is_edge(t_data *d, char *line)
{
	char	**edge;
	size_t	len;

	edge = ft_strsplit(line, '-');
	len = 0;
	while (edge[len] != NULL)
		len++;
	if (len != 2
			|| *edge[0] == '#' || *edge[0] == 'L'
			|| !are_existing_rooms(d, edge[0], edge[1]))
	{
		ft_strsplitdel(edge);
		return (NULL);
	}
	return (edge);
}

void	save_edge(t_data *d, t_graph *g, char **edge)
{
	int		from;
	int		to;
	t_node	*tmp;

	from = get_id(edge[0], d);
	to = get_id(edge[1], d);
	if (!g->nodes[from])
	{
		g->nodes[from] = malloc(sizeof(t_node));
		g->nodes[from]->name = d->name[to];
		g->nodes[from]->next = NULL;
		g->nodes[from]->verified = 0;
		g->nodes[from]->id = to;
	}
	else
	{
		tmp = g->nodes[from];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_node));
		tmp->next->verified = 0;
		tmp->next->name = d->name[to];
		tmp->next->id = to;
		tmp->next->next = NULL;
	}
}

void	alone_line(t_data *d, t_graph *g, char *line)
{
	char **edge;

	if (line == NULL)
	{
		ft_putendl("Error : no path");
		exit(0);
	}
	if (is_comment(line))
		;
	else if ((edge = is_edge(d, line)))
	{
		ft_putendl_fd(line, 1);
		save_edge(d, g, edge);
		ft_strdel(&line);
		ft_strsplitdel(edge);
	}
	g->n_vertices = d->rooms;
}

void	parse_edges(t_data *d, t_graph *g)
{
	char	*line;
	char	**edge;

	while (get_next_line(0, &line))
	{
		if (is_comment(line))
			ft_putendl(line);
		else if ((edge = is_edge(d, line)))
		{
			ft_putendl_fd(line, 1);
			save_edge(d, g, edge);
			ft_strsplitdel(edge);
		}
		ft_strdel(&line);
	}
}

void	check_double_edge(t_data *d, t_graph *g)
{
	int		i;
	int		j;
	t_node	*p;

	i = 0;
	while (i < d->rooms)
	{
		j = i + 1;
		while (j < d->rooms)
		{
			if (g->nodes[j])
			{
				p = g->nodes[j];
				while (p && p->id != i)
					p = p->next;
				if (p && p->id == i)
					add_single(g, i, j);
			}
			j++;
		}
		i++;
	}
}
