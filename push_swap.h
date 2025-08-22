/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 07:14:19 by yebi              #+#    #+#             */
/*   Updated: 2025/08/22 17:55:02 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*top;
	int				size;
}					t_stack;

void				print_error(void);
int					ft_atoi(const char *nptr);
int					ft_putchar(char c);
void				free_split(char **result);
char				**ft_split(char const *s, char c);
void				free_stack(t_stack *stack);

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				quick_sort(int *arr, int low, int high);
int					binary_search(int *arr, int n, int target);
int					assign_index(t_stack *a);
void				organize_stack(int argc, char **argv, t_stack *a);
void				sort_a_few(t_stack *a, t_stack *b);

int					find_index_in_chunk(t_stack *stack, int min, int max);
int					find_max_index_pos(t_stack *stack);
void				rotate_to_top_a(t_stack *a, int pos);
void				rotate_to_top_b(t_stack *b, int pos);
void				chunk_sort(t_stack *a, t_stack *b);

#endif
