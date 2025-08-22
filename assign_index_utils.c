/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 01:19:08 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/22 02:19:31 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[high]);
	return (i);
}

void	quick_sort(int *arr, int low, int high)
{
	int	piv_idx;

	if (low < high)
	{
		piv_idx = partition(arr, low, high);
		quick_sort(arr, low, piv_idx - 1);
		quick_sort(arr, piv_idx + 1, high);
	}
}

int	binary_search(int *arr, int n, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = n - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
