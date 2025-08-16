/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 01:19:32 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/17 01:33:03 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicates(int *vals, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (vals[i] == vals[i - 1])
		{
			free(vals);
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

static int	*stack_to_array(t_stack *a)
{
	int		*vals;
	t_list	*node;
	int		i;

	vals = (int *)malloc(sizeof(int) * a->size);
	if (!vals)
		return (NULL);
	i = 0;
	node = a->top;
	while (node)
	{
		vals[i] = node->value;
		node = node->next;
		i++;
	}
	return (vals);
}

void	assign_index(t_stack *a)
{
	int		*vals;
	t_list	*node;

	vals = stack_to_array(a);
	if (!vals)
		return ;
	quick_sort(vals, 0, a->size - 1);
	check_duplicates(vals, a->size);
	node = a->top;
	while (node)
	{
		node->index = binary_search(vals, a->size, node->value);
		node = node->next;
	}
	free(vals);
}
