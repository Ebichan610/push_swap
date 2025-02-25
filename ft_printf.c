/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:00:30 by yebi              #+#    #+#             */
/*   Updated: 2025/02/19 19:07:59 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		tmp;

	count = 0;
	tmp = 0;
	va_start(ap, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			tmp = check_specifier(ap, format);
			format++;
		}
		else
			tmp = ft_putchar(*format);
		if (tmp == -1)
			return (-1);
		count += tmp;
		format++;
	}
	va_end(ap);
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
