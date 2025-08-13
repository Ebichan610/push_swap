/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:39 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/11 19:45:48 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack *a)
{
    t_list *prev;
    t_list *last;

    if (a->top == NULL || a->top->next == NULL)
        return;
    prev = NULL;
    last = a->top;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = a->top;
    a->top = last;
}

void rrb(t_stack *b)
{
    t_list *prev;
    t_list *last;

    if (b->top == NULL || b->top->next == NULL)
        return;
    prev = NULL;
    last = b->top;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = b->top;
    b->top = last;
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}
