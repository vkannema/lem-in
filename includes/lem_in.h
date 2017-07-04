/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:18:17 by vkannema          #+#    #+#             */
/*   Updated: 2017/04/26 10:46:42 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libftprintf.h"
# define MAX 10000
# define NO_START "Error : no start or end"
# define NO_ANTS "Error : invalid ants format"
# define NO_ROOMS "Error : no rooms"
# define ILLEGAL_NAME "Error : Illegal name"
# define ERROR_ANTS 0

typedef struct		s_path
{
	int				ant;
	int				id;
	struct s_path	*next;
}					t_path;

typedef struct		s_data
{
	int				ants;
	int				tot;
	int				start;
	int				end;
	int				rooms;
	char			**ret;
	char			*name[MAX];
	t_path			*path;
	char			*output[MAX];
	int				len_path;
}					t_data;

typedef struct		s_node
{
	int				x;
	int				y;
	char			*name;
	int				id;
	int				verified;
	struct s_node	*next;
}					t_node;

typedef struct		s_queue
{
	int				id;
	int				parent;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_bfs
{
	t_queue			*queue;
	int				*output;
}					t_bfs;

typedef struct		s_graph
{
	t_node			*nodes[MAX];
	int				n_vertices;
	int				n_edges;
}					t_graph;

void				parse(t_graph *g, t_data *d);
void				init_graph(t_graph *graph);
t_queue				*ft_newlst(int id);
void				ft_push_back(t_queue **queue, int id, int parent);
void				get_path(t_data *d, t_graph *g, t_bfs *b);
t_path				*new_path(int id);
void				ft_push_front(t_path **path, int id);
void				move_ants(t_data *d);
void				ft_fatal(int i);
void				error_room(t_data *d);
void				error_edge(t_data *d, t_graph *g);
int					are_existing_rooms(t_data *d, char *e1, char *e2);
void				error_path(t_data *d, t_bfs *b);
void				free_list(t_data *d, t_graph *g, t_bfs *b);
char				**is_edge(t_data *d, char *line);
int					get_id(char *name, t_data *d);
void				save_edge(t_data *d, t_graph *g, char **edge);
void				alone_line(t_data *d, t_graph *g, char *line);
void				parse_edges(t_data *d, t_graph *g);
void				add_single(t_graph *g, int i, int j);
void				check_double_edge(t_data *d, t_graph *g);
int					is_comment(char *line);
t_queue				*del_first(t_queue *queue);
void				init_path(t_data *d, t_bfs *b);
void				add_single(t_graph *g, int i, int j);
int					get_id(char *name, t_data *d);
int					is_comment(char *line);
int					is_command(char *line);
int					is_wrap_end(char *line, int *is_end);
int					is_wrap_start(char *line, int *is_start);
#endif
