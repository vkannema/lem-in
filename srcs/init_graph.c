/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:01:36 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 10:39:53 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_path(t_data *d, t_bfs *b)
{
	int	i;

	i = 0;
	b->output = (int*)malloc(sizeof(int) * d->rooms);
	while (i < d->rooms)
	{
		b->output[i] = -3;
		i++;
	}
	b->output[d->start] = -1;
	b->output[d->end] = -2;
	b->queue = ft_newlst(d->start);
}

t_queue	*del_first(t_queue *queue)
{
	t_queue	*tmp;

	tmp = queue;
	if (queue->next)
		queue = queue->next;
	else
		queue = NULL;
	free(tmp);
	return (queue);
}

void	init_graph(t_graph *g)
{
	int	i;

	i = 0;
	g->n_vertices = 0;
	g->n_edges = 0;
	while (i < MAX + 1)
	{
		g->nodes[i] = NULL;
		i++;
	}
}
