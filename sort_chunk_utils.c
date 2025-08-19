/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 02:07:15 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/20 00:52:12 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index_pos(t_stack *stack)
{
	t_list	*cur;
	int		max_index;
	int		pos;
	int		i;

	cur = stack->top;
	max_index = -1;
	pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->index > max_index)
		{
			max_index = cur->index;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

void	rotate_to_top_a(t_stack *a, int pos)
{
	int	moves;

	if (pos == 0)
		return ;
	if (pos <= a->size / 2)
	{
		moves = pos;
		while (moves-- > 0)
			ra(a);
	}
	else
	{
		moves = a->size - pos;
		while (moves-- > 0)
			rra(a);
	}
}

void	rotate_to_top_b(t_stack *b, int pos)
{
	int	moves;

	if (pos == 0)
		return ;
	if (pos <= b->size / 2)
	{
		moves = pos;
		while (moves-- > 0)
			rb(b);
	}
	else
	{
		moves = b->size - pos;
		while (moves-- > 0)
			rrb(b);
	}
}
