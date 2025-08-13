/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:28 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/11 19:45:19 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *a)
{
    t_list *first;
    t_list *last;

    if (a->top == NULL || a->top->next == NULL)
        return;
    first = a->top;
    last = a->top;
    while (last->next != NULL)
        last = last->next;
    a->top = first->next;
    first->next = NULL;
    last->next = first;
}

void rb(t_stack *b)
{
    t_list *first;
    t_list *last;

    if (b->top == NULL || b->top->next == NULL)
        return;
    first = b->top;
    last = b->top;
    while (last->next != NULL)
        last = last->next;
    b->top = first->next;
    first->next = NULL;
    last->next = first;
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
