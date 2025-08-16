/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:39 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/17 01:44:19 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_stack *stack)
{
    t_list *first;
    t_list *last;

    if (stack->top == NULL || stack->top->next == NULL)
        return;
    first = NULL;
    last = stack->top;
    while (last->next != NULL)
    {
        first = last;
        last = last->next;
    }
    first->next = NULL;
    last->next = stack->top;
    stack->top = last;
}

void rra(t_stack *a)
{
   reverse_rotate(a);
   write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
   reverse_rotate(b);
   write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
