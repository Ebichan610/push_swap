/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 07:08:15 by ebichan           #+#    #+#             */
/*   Updated: 2025/02/23 07:09:40 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	ssize_t	count;

	count = 0;
	count = write(1, &c, 1);
	return ((int)count);
}

int	ft_puthexnbr_in_low(unsigned int n)
{
	char	c;
	ssize_t	count;
	ssize_t	tmp;

	count = 0;
	if (n >= 16)
	{
		tmp = ft_puthexnbr_in_low(n / 16);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (n % 16 >= 10)
		c = (n % 16) - 10 + 'a';
	else
		c = (n % 16) + '0';
	tmp = write(1, &c, 1);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return ((int)count);
}

int	ft_puthexnbr_in_up(unsigned int n)
{
	char	c;
	ssize_t	count;
	ssize_t	tmp;

	count = 0;
	if (n >= 16)
	{
		tmp = ft_puthexnbr_in_up(n / 16);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (n % 16 >= 10)
		c = (n % 16) - 10 + 'A';
	else
		c = (n % 16) + '0';
	tmp = write(1, &c, 1);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return ((int)count);
}

int	ft_puthexnbr_for_ptr(uintptr_t n)
{
	char	c;
	ssize_t	count;
	ssize_t	tmp;

	count = 0;
	if (n >= 16)
	{
		tmp = ft_puthexnbr_for_ptr(n / 16);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (n % 16 >= 10)
		c = (n % 16) - 10 + 'a';
	else
		c = (n % 16) + '0';
	tmp = write(1, &c, 1);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return ((int)count);
}

#include "utils.h"

static int	ft_putnbr_recursive(unsigned int n)
{
	int	count;
	int	tmp;

	count = 0;
	if (n >= 10)
	{
		tmp = ft_putnbr_recursive(n / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	tmp = ft_putchar((n % 10) + '0');
	if (tmp == -1)
		return (-1);
	count += tmp;
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;
	int	tmp;

	count = 0;
	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		tmp = ft_putchar('-');
		if (tmp == -1)
			return (-1);
		count += tmp;
		n = -n;
	}
	tmp = ft_putnbr_recursive((unsigned int)n);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return (count);
}

int	ft_putstr(char *s)
{
	ssize_t	count;
	ssize_t	tmp;

	count = 0;
	tmp = 0;
	if (s == NULL)
	{
		count = write(1, "(null)", 6);
		return ((int)count);
	}
	while (*s)
	{
		tmp = ft_putchar(*s);
		if (tmp == -1)
			return (-1);
		count += tmp;
		s++;
	}
	return ((int)count);
}


int	ft_putuintnbr(unsigned int n)
{
	char	c;
	ssize_t	count;
	ssize_t	tmp;

	count = 0;
	if (n >= 10)
	{
		tmp = ft_putuintnbr(n / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	c = (n % 10) + '0';
	tmp = write(1, &c, 1);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return ((int)count);
}
