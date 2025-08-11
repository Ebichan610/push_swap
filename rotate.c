/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:28 by ebichan           #+#    #+#             */
/*   Updated: 2025/03/30 17:58:33 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack *a)
{
    if(a -> top == NULL || a -> top -> next == NULL)
        return;
    t_list *tmp;
    tmp = (t_list *)malloc(sizeof(t_list));
    if(tmp == NULL)
        return;
    tmp = a -> top;
    a -> top = a -> top -> next;
    while(tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = a -> top;
    a -> top = NULL;
    free(tmp);
}

void rb(t_stack *b)
{
    if(b -> top == NULL || b -> top -> next == NULL)
        return;
    t_list *tmp;
    tmp = (t_list *)malloc(sizeof(t_list));
    if(tmp == NULL)
        return;
    tmp = b -> top;
    b -> top = b -> top -> next;
    while(tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = b -> top;
    b -> top = NULL;
    free(tmp);
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}
