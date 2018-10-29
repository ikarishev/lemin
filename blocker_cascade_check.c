/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocker_cascade_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:07:34 by ikarishe          #+#    #+#             */
/*   Updated: 2018/07/03 14:13:22 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	one_ant_pull(t_room *closest, t_room *room)
{
	room->last_pull = closest;
	if (closest->num_ants > 0)
	{
		closest->num_ants = closest->num_ants - 1;
		room->ant_name = closest->ant_name;
		if (closest->distance_from_start != 0)
			closest->reserved = 1;
		if (closest->distance_from_start == 0)
			closest->ant_name = closest->ant_name + 1;
		room->num_ants = room->num_ants + 1;
		room->reserved = 1;
	}
}

int		pull_from_closest_dis(t_room *room, t_list *rooms, int dis)
{
	t_room	*closest;
	t_list	*curr2;
	t_room	*temp;

	closest = NULL;
	if (room->distance_from_start == 0)
	{
		set_new_distance(rooms);
		return (dis);
	}
	curr2 = room->links;
	while (curr2->next != NULL)
	{
		temp = (t_room*)((t_list*)(curr2->content))->content;
		if (if_temp_closest(temp, room))
			closest = temp;
		if (closest != NULL)
			if (if_better_closest(temp, closest))
				closest = temp;
		curr2 = curr2->next;
	}
	if (closest == NULL)
		return (0);
	one_ant_pull(closest, room);
	return (pull_from_closest_dis(closest, rooms, dis + 1));
}

t_list	*get_nth_pos(t_list *end, int n)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = ((t_room*)(end->content))->links;
	while (curr->next != NULL)
	{
		if (i == n)
			break ;
		i++;
		curr = curr->next;
	}
	return (curr);
}

void	find_best_nth_move(t_list *rooms, t_list *end, int num_ants, int n)
{
	t_list	*curr;
	t_list	*nth_position;
	t_list	*best;
	t_room	*temp;
	t_two	num;

	nth_position = NULL;
	best = NULL;
	num.total_path_length = -100;
	num.curr_dis = -100;
	curr = ((t_room*)(end->content))->links;
	nth_position = get_nth_pos(end, n);
	while (curr->next != NULL)
	{
		temp = (t_room*)((t_list*)(curr->content))->content;
		if (num.curr_dis == -100)
			num.curr_dis = temp->distance_from_start;
		else if (num.curr_dis < temp->distance_from_start)
			break ;
		swap(curr, nth_position);
		set_best(&(num.total_path_length), &curr, &best, rooms);
		reset(rooms, &curr, &nth_position, num_ants);
	}
	if (best != NULL && nth_position != NULL)
		swap(best, nth_position);
}

void	blocker_cascade_check(t_list *rooms, t_list *end, int num_ants)
{
	int max_possible_moves;
	int n;
	int p_bar;

	(void)end;
	(void)num_ants;
	n = 0;
	p_bar = 0;
	max_possible_moves = get_max_possible_moves(rooms);
	if (max_possible_moves >= 10)
		put_progress_bar(max_possible_moves);
	while (n < max_possible_moves)
	{
		if (max_possible_moves >= 10)
			write(1, "*", 1);
		find_best_nth_move(rooms, end, num_ants, n);
		n++;
	}
	if (max_possible_moves >= 10)
		write(1, "\n", 1);
	clear_reservations(rooms);
	reset_distance(rooms);
	set_distance_from_start(rooms);
	reset_ants(rooms);
	set_ants_in_start(rooms, num_ants);
}
