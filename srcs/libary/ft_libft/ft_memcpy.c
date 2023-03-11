/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:22:58 by segurbuz          #+#    #+#             */
/*   Updated: 2022/12/07 16:22:59 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	i = 0;
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst == src || !len)
		return (dst);
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
