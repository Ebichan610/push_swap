/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:00:30 by yebi              #+#    #+#             */
/*   Updated: 2025/08/11 19:14:41 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	ssize_t	count;

	count = 0;
	count = write(1, &c, 1);
	return ((int)count);
}

int	ft_printf(const char *format)
{
	int		count;
	int		tmp;

	count = 0;
	tmp = 0;
	if (format == NULL)
		return (-1);
	while (*format)
	{
		tmp = ft_putchar(*format);
		if (tmp == -1)
			return (-1);
		count += tmp;
		format++;
	}
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", 'a',
// 			"abcde", "abcde", 123, -123, -23, -23, -23));
// 	printf("%d\n", printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", 'a', "abcde",
// 			"abcde", 123, -123, -23, -23, -23));
// 	return (0);
// }
