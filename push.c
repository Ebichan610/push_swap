/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:57:21 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/11 19:31:22 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack *a, t_stack *b)
{
    if(b -> top == NULL)
        return;
    t_list *tmp;
    tmp = (t_list *)malloc(sizeof(t_list));
    if(tmp == NULL)
        return;
    tmp = b -> top;
    b -> top -> next = a -> top;
    a -> top = tmp;
    b -> top = tmp -> next;
    a -> size += 1;
    b -> size -= 1;
    free(tmp);
}

void pb(t_stack *a, t_stack *b)
{
    if(a -> top == NULL)
        return;
    t_list *tmp;
    tmp = (t_list *)malloc(sizeof(t_list));
    if(tmp == NULL)
        return;
    tmp = a -> top;
    a -> top -> next = b -> top;
    a -> top = tmp -> next;
    b -> top = tmp;
    a -> size -= 1;
    b -> size += 1;
    free(tmp);
}
