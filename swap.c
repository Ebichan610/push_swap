/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:13 by ebichan           #+#    #+#             */
/*   Updated: 2025/03/02 13:49:02 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *a)
{
    if(a -> top == NULL || a -> top -> next == NULL)
        return;
    t_list *tmp;
    tmp = (t_list *)malloc(sizeof(t_list));
    if(tmp == NULL)
        return;
    tmp = a -> top -> next;
    a -> top -> next -> next = a -> top -> next;
    a -> top -> next = tmp -> next;
    a -> top = tmp;
    free(tmp);
}

void sb(t_stack *b)
{
    if(b -> top == NULL || b -> top -> next == NULL)
        return;
    t_list *tmp;
    tmp = (t_list *)malloc(sizeof(t_list));
    if(tmp == NULL)
        return;
    tmp = b -> top -> next;
    b -> top -> next -> next = b -> top -> next;
    b -> top -> next = tmp -> next;
    b -> top = tmp;
    free(tmp);
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}
