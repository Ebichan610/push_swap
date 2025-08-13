/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:13 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/11 19:44:51 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *a)
{
    t_list *first;
    t_list *second;

    if (a->top == NULL || a->top->next == NULL)
        return;
    first = a->top;
    second = a->top->next;
    first->next = second->next;
    second->next = first;
    a->top = second;
}

void sb(t_stack *b)
{
    t_list *first;
    t_list *second;

    if (b->top == NULL || b->top->next == NULL)
        return;
    first = b->top;
    second = b->top->next;
    first->next = second->next;
    second->next = first;
    b->top = second;
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}
