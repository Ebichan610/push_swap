/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:21 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/17 01:33:35 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack *a, t_stack *b)
{
    t_list *tmp;

    if (b->top == NULL)
        return;
    tmp = b->top;
    b->top = tmp->next;
    tmp->next = a->top;
    a->top = tmp;
    a->size++;
    b->size--;
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    t_list *tmp;

    if (a->top == NULL)
        return;
    tmp = a->top;
    a->top = tmp->next;
    tmp->next = b->top;
    b->top = tmp;
    a->size--;
    b->size++;
    write(1, "pb\n", 3);
}
