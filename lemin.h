/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:11:22 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 15:00:08 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "Libft_Final/libft.h"
# include "Libft_Final/get_next_line.h"

typedef struct s_room	t_room;

struct			s_room
{
	char	*name;
	char	*name2;
	int		x;
	int		y;
	int		distance_from_start;
	int		distance_from_end;
	int		num_ants;
	int		ant_name;
	int		reserved;
	t_room	*last_pull;
	t_list	*links;
};

typedef struct	s_two
{
	int curr_dis;
	int total_path_length;
}				t_two;

t_list			*read_from_stdin(int *num_ants);
void			grab_number_of_ants(int *num_ants);
t_list			*add_room(t_list *head, char *line, int flag);
void			make_link(t_list *head, char *line);
void			print_all(t_list *head);
void			set_distance_from_start(t_list *rooms);
void			set_distance_from_end(t_list *rooms);
void			solve(t_list *rooms, int num_ants);
void			sort_end_links(t_list *rooms, int num_ants);
void			check_room_formatting(t_list *rooms);
void			check_path_exists(t_list *rooms);
void			reset_distance(t_list *rooms);
void			set_new_distance(t_list *rooms);
int				push_all_remaining(t_list *rooms, int *ants_in_end, int flag);
void			print_stuff(int ant_name, char *room_name);
void			clear_reservations(t_list *rooms);
void			blocker_cascade_check(t_list *rooms, t_list *end, int num_ants);
void			swap(t_list *a, t_list *b);
void			set_ants_in_start(t_list *rooms, int num_ants);
void			put_links(t_list *links);
void			solve_unsorted(t_list *rooms, int num_ants);
void			init_start_room(t_room *room);
void			init_end_room(t_room *room);
void			init_room(t_room *room);

void			print_start(t_list *head);
void			put_progress_bar(int max);
void			reset_1(t_list *rooms);
void			reset_2(t_list *rooms, int num_ants);
void			reset(t_list *rooms, t_list **curr, t_list **nth_position,
		int num_ants);
void			reset_ants(t_list *rooms);
int				get_end_links(t_list *rooms);
int				get_start_links(t_list *rooms);
int				get_max_possible_moves(t_list *rooms);
int				if_temp_closest(t_room *temp, t_room *room);
int				if_better_closest(t_room *temp, t_room *closest);
void			get_path_len(t_room *temp, t_list *rooms,
		int *dis, int *total_path_length);
int				get_total_path_length(t_list *rooms);
void			set_best(int *total_path_length, t_list **curr,
		t_list **best, t_list *rooms);
int				pull_from_closest_dis(t_room *room, t_list *rooms, int dis);
void			check_coordinates(char *line, t_list *curr, t_list *rooms);
void			check_room_formatting(t_list *rooms);
void			check_coord_overlap(char *line, t_list *curr2);
void			push_one_ant(t_list *curr, t_room *temp,
		int *ants_in_end, int *movement);
void			links_action(int *links_section, char *line, t_list *head);
void			reset_distance(t_list *rooms);
int				ants_in_start(t_list *rooms);
int				start_empty(t_list *rooms);
void			reset_rooms(t_list *rooms);
void			clear_reservations(t_list *rooms);
int				available_start_links(t_list *rooms);
void			print_stuff(int ant_name, char *room_name);
void			move_one_from_closest(t_room *closest, t_room *room);
int				should_be_closest(t_room *temp, t_room *room);
int				better_closest(t_room *temp, t_room *closest);
void			move_ant_closest(t_room *closest, t_room *room);

#endif
