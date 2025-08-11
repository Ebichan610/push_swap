/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:03:51 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/11 19:03:55 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

ssize_t	ft_strlen(char *s)
{
	ssize_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	ssize_t	s1_len;
	ssize_t	s2_len;
	char	*start;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	start = result;
	while (s1_len-- > 0)
		*result++ = *s1++;
	while (s2_len-- > 0)
		*result++ = *s2++;
	*result = '\0';
	return (start);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_cpy;

	s_cpy = (unsigned char *)s;
	while (n-- > 0)
	{
		*s_cpy = 0;
		s_cpy++;
	}
}
