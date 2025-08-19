/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:02:32 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/19 16:07:52 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (sign == 1 && (result > LONG_MAX / 10 || (result == LONG_MAX / 10
					&& (*nptr - '0') >= LONG_MAX % 10)))
			return (INT_MAX);
		if (sign == -1 && (result > -(LONG_MIN / 10) || (result == -(LONG_MIN
						/ 10) && (*nptr - '0') > -(LONG_MIN % 10))))
			return (INT_MIN);
		result = result * 10 + (long)(*nptr - '0');
		nptr++;
	}
	return ((int)(result * sign));
}
