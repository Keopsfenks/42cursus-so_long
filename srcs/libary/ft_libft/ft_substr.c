/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:56:36 by segurbuz          #+#    #+#             */
/*   Updated: 2022/12/15 17:56:37 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	rule;
	char	*array;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	rule = ft_strlen(s + start);
	if (rule < len)
		len = rule;
	array = malloc(len + 1);
	if (!array)
		return (NULL);
	ft_strlcpy(array, s + start, len + 1);
	return (array);
}
