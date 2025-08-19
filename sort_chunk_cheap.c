/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* find_cheapest_utils.c                              :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/08/20 00:50:00 by yebi              #+#    #+#             */
/* Updated: 2025/08/20 00:50:00 by yebi             ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

static void	update_cheapest(int cost, int pos, int *min_cost, int *cheapest_pos)
{
	if (*min_cost == -1 || cost < *min_cost)
	{
		*min_cost = cost;
		*cheapest_pos = pos;
	}
}

int	find_index_in_chunk(t_stack *stack, int min, int max)
{
	t_list	*cur;
	int		cheapest_pos;
	int		min_cost;
	int		pos;

	cur = stack->top;
	pos = 0;
	min_cost = -1;
	cheapest_pos = -1;
	while (cur)
	{
		if (cur->index >= min && cur->index <= max)
		{
			update_cheapest(calculate_cost(pos, stack->size), pos, &min_cost,
				&cheapest_pos);
		}
		cur = cur->next;
		pos++;
	}
	return (cheapest_pos);
}
