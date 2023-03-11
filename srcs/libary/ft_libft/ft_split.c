/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:37:22 by segurbuz          #+#    #+#             */
/*   Updated: 2022/12/25 14:37:24 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	charcount(const char *s, char c, int rule)
{
	size_t	i;

	i = 0;
	if (rule)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	else
	{
		while (s[i] && s[i] == c)
			i++;
	}
	return (i);
}

static int	wordcount(const char *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (word);
		while (*s != c && *s)
			s++;
		word++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	rule;
	size_t	i;

	array = (char **)malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!s || !array)
		return (NULL);
	i = 0;
	rule = wordcount(s, c);
	while (i < rule)
	{
		s += charcount(s, c, 0);
		array[i++] = ft_substr(s, 0, charcount(s, c, 1));
		s += charcount(s, c, 1);
	}
	array[i] = NULL;
	return (array);
}
