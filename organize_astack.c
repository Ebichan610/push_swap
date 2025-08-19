/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_astack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:35:32 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/19 16:18:03 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_num(t_stack *stack, int num)
{
	t_list	*node;
	t_list	*tmp;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (1);
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
	return (0);
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
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		result = result * 10 + (str[i++] - '0');
		if (sign == 1 && result > INT_MAX)
			return (1);
		if (sign == -1 && (result * (-1)) < INT_MIN)
			return (1);
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

static int	process_args(char **args, t_stack *a)
{
	int	i;
	int	num;

	i = 0;
	while (args[i] != NULL)
	{
		if (check_num(args[i]))
			return (1);
		num = ft_atoi(args[i]);
		if (has_duplicate(a, num))
			return (1);
		if (push_num(a, num))
			return (1);
		i++;
	}
	return (0);
}

void	organize_astack(int argc, char *argv[], t_stack *a)
{
	char	**split_result;
	int		flag;

	if (argc == 2)
	{
		split_result = ft_split(argv[1], ' ');
		if (split_result == NULL || split_result[0] == NULL)
			print_error();
		flag = process_args(split_result, a);
		free_split(split_result);
		if (flag)
		{
			free_stack(a);
			print_error();
		}
	}
	else
	{
		flag = process_args(&argv[1], a);
		if (flag)
		{
			free_stack(a);
			print_error();
		}
	}
}
