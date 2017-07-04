/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_edge_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:42:56 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 10:44:41 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_id(char *name, t_data *d)
{
	int	i;

	i = 0;
	while (ft_strcmp(name, d->name[i]))
		i++;
	return (i);
}

void	add_single(t_graph *g, int i, int j)
{
	t_node	*tmp;
	t_node	*cop;

	cop = malloc(sizeof(t_node));
	cop->id = j;
	cop->next = NULL;
	cop->verified = 0;
	if (g->nodes[i])
	{
		tmp = g->nodes[i];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = cop;
	}
	else
		free(cop);
}
