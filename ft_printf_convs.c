/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:33:45 by ebichan           #+#    #+#             */
/*   Updated: 2025/02/25 14:34:53 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_char(int c)
{
	int	count;

	count = ft_putchar(c);
	return (count);
}

int	conv_hexint(int num, char c)
{
	int	count;

	if (c == 'x')
		count = ft_puthexnbr_in_low(num);
	else
		count = ft_puthexnbr_in_up(num);
	return (count);
}

int	conv_int(int num)
{
	int	count;

	count = ft_putnbr(num);
	return (count);
}

int	conv_percent(void)
{
	int	count;

	count = ft_putchar('%');
	return (count);
}

int	conv_pointer(void *ptr)
{
	int	count;

	if (ptr == NULL)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	count = (int)write(1, "0x", 2);
	count += ft_puthexnbr_for_ptr((uintptr_t)ptr);
	return (count);
}

int	conv_str(char *str)
{
	int	count;

	count = ft_putstr(str);
	return (count);
}

int	conv_uint(unsigned int num)
{
	int	count;

	count = ft_putuintnbr(num);
	return (count);
}
