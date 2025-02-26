/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 07:14:19 by yebi              #+#    #+#             */
/*   Updated: 2025/02/25 14:31:05 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

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

#endif