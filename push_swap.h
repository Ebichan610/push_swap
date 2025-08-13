/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 07:14:19 by yebi              #+#    #+#             */
/*   Updated: 2025/08/14 01:44:46 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "get_next_line.h"

typedef struct s_list
{
	int				value;
	struct	s_list	*next;
}	t_list;

typedef	struct	s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

void print_error();
int	ft_atoi(const char *nptr);
int	ft_putchar(char c);
int	ft_printf(char const *format);
void	free_split(char **result, int i_max);
char	**ft_split(char const *s, char c);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void sort_two(t_stack *a);
void sort_three(t_stack *a);
void sort_five(t_stack *a, t_stack *b);

#endif
