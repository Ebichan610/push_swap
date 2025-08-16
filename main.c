/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:36:05 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/17 02:00:38 by ebichan          ###   ########.fr       */
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

int	is_sorted(t_stack *stack)
{
	t_list	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
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
		assign_index(&a);
		if (a.size <= 6 && a.size > 1)
			sort_a_few(&a, &b);
		else
			chunk_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
