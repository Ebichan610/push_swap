/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:36:05 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/19 16:29:24 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list	*tmp;
	t_list	*current;

	if (!stack)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	stack->top = NULL;
	stack->size = 0;
}

static int	is_sorted(t_stack *stack)
{
	t_list	*tmp;

	if (stack == NULL || stack->top == NULL)
		return (1);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	organize_astack(argc, argv, &a);
	if (!is_sorted(&a))
	{
		if (assign_index(&a))
		{
			free_stack(&a);
			print_error();
		}
		if (a.size <= 6)
			sort_a_few(&a, &b);
		else
			chunk_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
