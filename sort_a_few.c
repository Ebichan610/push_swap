/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_few.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:54:16 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/16 20:38:44 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_min(t_stack *a)
{
    t_list *tmp;
    int min;

    tmp = a->top;
    min = tmp->value;
    while (tmp != NULL)
    {
        if (tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    return min;
}

static void move_min(t_stack *a, int min)
{
   t_list *tmp;
   int i;
   int j;

   tmp = a->top;
   i = 0;
   j = 0;
   while(tmp != NULL &&tmp->value != min)
   {
        i++;
        tmp = tmp->next;
   }
   if(i <= 2)
   {
        while(j++<i)
            ra(a);
   }
   else
   {
        while(j++ < a->size - i)
            rra(a);
   }
}

static void sort_three(t_stack *a)
{
    int x;
    int y;
    int z;

    x = a->top->value;
    y = a->top->next->value;
    z = a->top->next->next->value;
    if (x > y && y < z && x < z)
        sa(a);
    else if (x > y && y > z)
    {
        sa(a);
        rra(a);
    }
    else if (x > y && y < z && x > z)
        ra(a);
    else if (x < y && y > z && x < z)
    {
        sa(a);
        ra(a);
    }
    else if (x < y && y > z && x > z)
        rra(a);
}

static void sort_six(t_stack *a, t_stack *b)
{
    int min;
    while (a->size > 3)
    {
        min = find_min(a);
        move_min(a, min);
        pb(a, b);
    }
    sort_three(a);
    while (b->size > 0)
        pa(a, b);
}

void sort_a_few(t_stack *a, t_stack *b)
{
    if(a->size == 2&&(a->top->value > a->top->next->value))
        sa(a);
    else
        sort_six(a,b);
}
