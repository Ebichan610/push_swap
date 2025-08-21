/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 01:19:32 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/21 23:51:02 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *a)
{
	int		*vals;
	t_list	*node;
	int		i;

	vals = (int *)malloc(sizeof(int) * a->size);
	if (vals == NULL)
		return (NULL);
	i = 0;
	node = a->top;
	while (node != NULL)
	{
		vals[i] = node->value;
		node = node->next;
		i++;
	}
	return (vals);
}

int	assign_index(t_stack *a)
{
	int		*vals;
	t_list	*node;

	vals = stack_to_array(a);
	if (vals == NULL)
		return (1);
	quick_sort(vals, 0, a->size - 1);
	node = a->top;
	while (node != NULL)
	{
		node->index = binary_search(vals, a->size, node->value);
		node = node->next;
	}
	free(vals);
	return (0);
}
