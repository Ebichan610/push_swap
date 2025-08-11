/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:39 by ebichan           #+#    #+#             */
/*   Updated: 2025/03/30 17:59:10 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack *a)
{
    if(a -> top == NULL || a -> top -> next == NULL)
        return;
    t_list *tmp;
    tmp = (t_list *)malloc(sizeof(t_list));
    if(tmp == NULL)
        return;
    tmp = a -> top;
    while(tmp -> next -> next != NULL)
        tmp = tmp -> next;
    tmp -> next -> next = a -> top;
    a -> top = tmp -> next;
    tmp -> next = NULL;
    free(tmp);
}

void rrb(t_stack *b)
{
    if(b -> top == NULL || b -> top -> next == NULL)
        return;
    t_list *tmp;
    tmp = (t_list *)malloc(sizeof(t_list));
    if(tmp == NULL)
        return;
    tmp = b -> top;
    while(tmp -> next -> next != NULL)
        tmp = tmp -> next;
    tmp -> next -> next = b -> top;
    b -> top = tmp -> next;
    tmp -> next = NULL;
    free(tmp);
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}
