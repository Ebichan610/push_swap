/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:58:34 by ebichan           #+#    #+#             */
/*   Updated: 2025/02/23 07:07:30 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_puthexnbr_in_low(unsigned int n);
int	ft_puthexnbr_in_up(unsigned int n);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putuintnbr(unsigned int n);
int	ft_puthexnbr_for_ptr(uintptr_t n);
int	ft_printf(char const *format, ...);
int	check_specifier(va_list ap, char const *format);
int	conv_char(int c);
int	conv_hexint(int num, char c);
int	conv_int(int num);
int	conv_percent(void);
int	conv_pointer(void *ptr);
int	conv_str(char *str);
int	conv_uint(unsigned int num);

#endif
