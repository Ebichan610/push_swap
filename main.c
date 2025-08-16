/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:36:05 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/17 01:33:03 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_stack(t_stack *stack)
{
    t_list *tmp;
    while (stack->top != NULL)
    {
        tmp = stack->top;
        stack->top = tmp->next;
        free(tmp);
    }
    stack->size = 0;
}

int main(int argc, char* argv[])
{
    t_stack a;
    t_stack b;
    
    a.top = NULL;
    a.size = 0;
    b.top = NULL;
    b.size = 0;
    if(argc < 2)
        print_error();
    organize_astack(argc,argv,&a);
   
}
