/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:53:31 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/16 01:30:44 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_index_in_chunk(t_stack *stack, int min, int max)
{
    t_list *cur;
    int pos;

    cur = stack->top;
    pos = 0;
    while (cur)
    {
        if (cur->index >= min && cur->index <= max)
            return pos;
        cur = cur->next;
        pos++;
    }
    return -1;
}

static int find_max_index_pos(t_stack *stack)
{
    t_list *cur;
    int max;
    int pos;
    int i;

    cur = stack->top;
    max = -1;
    pos = 0;
    i = 0;
    while (cur)
    {
        if (cur->index > max)
        {
            max = cur->index;
            pos = i;
        }
        cur = cur->next;
        i++;
    }
    return pos;
}

static void rotate_to_top_a(t_stack *a, int pos)
{
    if (pos <= a->size / 2)
        while (pos-- > 0)
            ra(a);
    else
    {
        pos = a->size - pos;
        while (pos-- > 0)
            rra(a);
    }
}

static void rotate_to_top_b(t_stack *b, int pos)
{
    if (pos <= b->size / 2)
        while (pos-- > 0)
            rb(b);
    else
    {
        pos = b->size - pos;
        while (pos-- > 0)
            rrb(b);
    }
}

/* --- チャンクソート本体 --- */
void chunk_sort(t_stack *a, t_stack *b)
{
    int chunk_size;
    int min;
    int max;
    int total;
    int pos;

    assign_index(a);           // インデックス付与
    total = a->size;
    chunk_size = (total <= 100) ? 20 : 45;  // チャンクの大きさ
    min = 0;
    max = chunk_size - 1;

    while (a->size > 0)
    {
        pos = find_index_in_chunk(a, min, max);
        if (pos == -1)
        {
            min += chunk_size;
            max += chunk_size;
            if (max >= total)
                max = total - 1;
            continue;
        }
        rotate_to_top_a(a, pos);
        pb(a, b);
    }

    while (b->size > 0)
    {
        pos = find_max_index_pos(b);
        rotate_to_top_b(b, pos);
        pa(a, b);
    }
}
