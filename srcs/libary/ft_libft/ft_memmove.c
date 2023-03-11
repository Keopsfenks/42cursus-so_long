/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:02:33 by segurbuz          #+#    #+#             */
/*   Updated: 2022/12/07 18:02:35 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	i = 1;
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst == src || !len)
		return (dst);
	if (src1 < dst1)
	{
		while (i <= len)
		{
			dst1[len - i] = src1[len - i];
			i++;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
