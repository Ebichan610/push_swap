/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:22:06 by ebichan           #+#    #+#             */
/*   Updated: 2025/08/22 17:54:55 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *str, char c)
{
	size_t	word_count;
	size_t	in_word;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		if (!in_word && *str != c)
		{
			word_count++;
			in_word = 1;
		}
		else if (in_word && *str == c)
			in_word = 0;
		str++;
	}
	return (word_count);
}

static char	*strndup_split(char const *s, size_t n)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(sizeof(char) * (n + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**words_split(char **result, char const *s, char c,
		size_t word_count)
{
	size_t	i;
	size_t	n;

	i = 0;
	while (i < word_count)
	{
		n = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			n++;
			s++;
		}
		result[i] = strndup_split(s - n, n);
		if (result[i] == NULL)
		{
			free_split(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	word_count = count_words(s, c);
	if (word_count == 0)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	return (words_split(result, s, c, word_count));
}

// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     int i, j;
//     char **split_result;

//     if (argc != 2)
//     {
//         printf("Usage: %s \"string to split\"\n", argv[0]);
//         return (1);
//     }

//     split_result = ft_split(argv[1], ' ');
//     if (!split_result)
//     {
//         printf("Error: split failed or invalid input\n");
//         return (1);
//     }

//     i = 0;
//     while (split_result[i])
//     {
//         printf("word[%d]: '%s'\n", i, split_result[i]);
//         i++;
//     }

//     free_split(split_result);
//     return (0);
// }
