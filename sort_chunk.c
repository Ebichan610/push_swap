/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:53:31 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/22 10:39:06 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_chunk_range(int *min, int *max, int chunk, int total)
{
	*min += chunk;
	*max += chunk;
	if (*max >= total)
		*max = total - 1;
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	min_idx;
	int	max_idx;
	int	total_size;
	int	pos;

	total_size = a->size;
	min_idx = 0;
	max_idx = chunk_size - 1;
	while (a->size > 0)
	{
		pos = find_index_in_chunk(a, min_idx, max_idx);
		if (pos == -1)
			update_chunk_range(&min_idx, &max_idx, chunk_size, total_size);
		else
		{
			rotate_to_top_a(a, pos);
			pb(a, b);
			if (b->size > 1 && b->top->index < (min_idx + (chunk_size / 2)))
				rb(b);
		}
	}
}

static void	push_sorted_to_a(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->size > 0)
	{
		pos = find_max_index_pos(b);
		rotate_to_top_b(b, pos);
		pa(a, b);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;

	if (a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 40;
	push_chunks_to_b(a, b, chunk_size);
	push_sorted_to_a(a, b);
}
