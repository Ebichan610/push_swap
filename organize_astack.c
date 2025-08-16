/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_astack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:35:32 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/17 01:59:51 by ebichan          ###   ########.fr       */
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

static int	check_num(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
    if (str[i] == '-')
        sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result * 10 + (str[i++] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && -result < INT_MIN))
			return (-1);
	}
	return (0);
}

static int	has_duplicate(t_stack *a, int num)
{
	t_list	*tmp;

	tmp = a->top;
	while (tmp != NULL)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	process_args(int count, char **args, t_stack *a)
{
	int	i;
	int	num;

	i = 0;
	while (i < count)
	{
		if (check_num(args[i]) == -1)
			print_error();
		num = ft_atoi(args[i]);
		if (has_duplicate(a, num))
			print_error();
		push_num(a, num);
		i++;
	}
}

void	organize_astack(int argc, char *argv[], t_stack *a)
{
	char	**split_result;
	int		word_count;

	if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		if (split_result == NULL || split_result[0] == NULL)
			print_error();
		word_count = 0;
		while (split_result[word_count])
			word_count++;
		process_args(word_count, split_result, a);
		free_split(split_result);
	}
	else
	{
		process_args(argc - 1, &argv[1], a);
	}
}
