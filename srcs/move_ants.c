/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:22:52 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 10:40:03 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		has_reached_end(t_data *d, int *ants)
{
	int i;

	i = 0;
	while (i < d->ants)
	{
		if (ants[i++] < d->len_path)
			return (0);
	}
	return (1);
}

void	print_moves(t_data *d, int *ants, int *path_tab)
{
	int i;

	i = 0;
	while (i < d->ants)
	{
		if (ants[i] > -1 && ants[i] < d->len_path)
			ft_printf("L%d-%s ", i + 1, d->name[path_tab[ants[i]]]);
		i++;
	}
}

int		lstlen(t_path *path)
{
	t_path	*tmp;
	int		i;

	i = 0;
	tmp = path;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		*ft_lstinttab(t_path *path)
{
	t_path	*tmp;
	int		*ret;
	int		i;

	i = 0;
	tmp = path;
	ret = malloc(sizeof(int) * lstlen(path));
	while (tmp)
	{
		ret[i] = tmp->id;
		i++;
		tmp = tmp->next;
	}
	return (ret);
}

void	move_ants(t_data *d)
{
	int *ants;
	int i;
	int j;
	int *path_tab;

	if (!(ants = malloc(sizeof(int) * (d->ants))))
		return ;
	ft_memset(ants, -1, sizeof(int) * (d->ants));
	d->len_path = lstlen(d->path);
	path_tab = ft_lstinttab(d->path);
	j = 0;
	while (!has_reached_end(d, ants))
	{
		i = 0;
		while (i < j)
			ants[i++]++;
		print_moves(d, ants, path_tab);
		if (!has_reached_end(d, ants))
			ft_printf("\n");
		if (j <= d->ants)
			j++;
	}
	free(ants);
	free(path_tab);
}
