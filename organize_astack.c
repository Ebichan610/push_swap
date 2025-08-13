/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_astack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:35:32 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/13 21:29:53 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_num(t_stack *stack, int num)
{
    t_list *node;
    t_list *tmp;

    node = (t_list *)malloc(sizeof(t_list));
    if (node == NULL)
        return;
    node->value = num;
    node->next = NULL;

    if (stack->top == NULL)
        stack->top = node;
    else
    {
        tmp = stack->top;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = node;
    }
    stack->size++;
}

static int check_num(char** strs)
{
    int i;
    i = 0;
    while(strs[i] != NULL)
    {
        int j;
        j = 0;
        if(str[j]!= '-' && (str[j] < '0' || str[j] > '9'))
        return (-1);
        j++;
        while(str[j] != '\0')
        {
            if(str[j] < '0' || str[j] > '9')
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

void organize_astack(int argc, char **argv, t_stack *a)
{
    int     i;
    int     j;
    int     num;
    char  **split_result;
    
    i = 1;
    while (i < argc)
    {
        split_result = ft_split(argv[i], ' ');
        if (split_result == NULL)
        {
            print_error();
            return;
        }
        j = 0;
        if (check_num(split_result) == -1)
        {
            free_split(split_result, j);
            return;
        }
        while (split_result[j] != NULL)
        {
            num = ft_atoi(split_result[j]);
            push_num(a, num);
            j++;
        }
        free_split(split_result, j);
        i++;
    }
}
