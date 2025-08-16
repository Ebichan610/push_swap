/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:13 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/17 01:39:37 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack *stack)
{
    t_list *first;
    t_list *second;

    if (stack->top == NULL || stack->top->next == NULL)
        return;
    first = stack->top;
    second = stack->top->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void sa(t_stack *a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}
