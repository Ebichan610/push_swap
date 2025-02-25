/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:12:18 by ebichan           #+#    #+#             */
/*   Updated: 2025/02/19 18:49:29 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(va_list ap, char const *format)
{
	int	count;

	count = 0;
	format++;
	if (*format == 'c')
		count = conv_char(va_arg(ap, int));
	else if (*format == 's')
		count = conv_str(va_arg(ap, char *));
	else if (*format == 'p')
		count = conv_pointer(va_arg(ap, void *));
	else if (*format == 'd' || *format == 'i')
		count = conv_int((long)va_arg(ap, int));
	else if (*format == 'u')
		count = conv_uint(va_arg(ap, unsigned int));
	else if (*format == 'x' || *format == 'X')
		count = conv_hexint(va_arg(ap, int), *format);
	else
		count = conv_percent();
	return (count);
}
