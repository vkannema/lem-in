/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:36:00 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 11:09:22 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_present(int id, int *output)
{
	if (output[id] >= 0)
		return (1);
	return (0);
}

void	add_to_node(t_node *tmp, t_bfs *b, int i)
{
	int	id;
	int	parent;

	while (tmp)
	{
		if (!is_present(tmp->id, b->output))
		{
			id = tmp->id;
			parent = i;
			ft_push_back(&b->queue, id, parent);
			tmp->verified = 1;
		}
		tmp = tmp->next;
	}
}

void	get_output(t_data *d, t_graph *g, t_bfs *b)
{
	t_node	*tmp;
	int		i;

	init_path(d, b);
	while (b->queue)
	{
		i = b->queue->id;
		if (b->output[i] < 0 && b->output[i] != -1)
			b->output[i] = b->queue->parent;
		b->queue = del_first(b->queue);
		if (g->nodes[i])
		{
			tmp = g->nodes[i];
			add_to_node(tmp, b, i);
		}
	}
}

void	get_end(t_data *d, t_bfs *b, int id)
{
	if (b->output[id] == -1)
		return ;
	if (!d->path)
		d->path = new_path(id);
	else
		ft_push_front(&d->path, id);
	get_end(d, b, b->output[id]);
}

void	get_path(t_data *d, t_graph *g, t_bfs *b)
{
	get_output(d, g, b);
	if (b->output[d->end] == -2)
	{
		ft_putendl("Error : no path");
		exit(0);
	}
	get_end(d, b, d->end);
}
