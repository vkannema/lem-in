/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:17:22 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 11:03:55 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	env_init(t_data *env)
{
	int	i;

	i = 0;
	env->ants = 0;
	env->start = -1;
	env->end = -1;
	env->tot = 0;
	env->rooms = 0;
	env->ret = NULL;
	while (i < MAX)
	{
		env->output[i] = NULL;
		i++;
	}
	env->path = NULL;
}

int		main(void)
{
	t_data	env;
	t_graph	graph;
	t_bfs	bfs;

	env_init(&env);
	init_graph(&graph);
	parse(&graph, &env);
	get_path(&env, &graph, &bfs);
	error_path(&env, &bfs);
	move_ants(&env);
	free_list(&env, &graph, &bfs);
	return (0);
}
