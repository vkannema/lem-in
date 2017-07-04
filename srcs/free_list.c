/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:34:17 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 10:34:26 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_nodes(t_graph *g, t_data *d)
{
	int		i;
	t_node	*tmp;
	t_node	*tmp2;

	i = 0;
	while (i < d->rooms)
	{
		if (g->nodes[i])
		{
			tmp = g->nodes[i];
			while (tmp)
			{
				tmp2 = tmp;
				free(tmp2);
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void	free_path(t_data *d)
{
	t_path	*tmp;
	t_path	*tmp2;

	tmp = d->path;
	while (tmp)
	{
		tmp2 = tmp;
		free(tmp2);
		tmp = tmp->next;
	}
}

void	free_list(t_data *d, t_graph *g, t_bfs *b)
{
	t_queue	*tmp2;
	t_queue	*tmp;

	tmp = b->queue;
	while (tmp)
	{
		tmp2 = tmp;
		free(tmp2);
		tmp = tmp->next;
	}
	free(b->output);
	free_nodes(g, d);
	free_path(d);
}
