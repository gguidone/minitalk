/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:03:58 by gguidone          #+#    #+#             */
/*   Updated: 2023/02/21 11:10:48 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	char			*dst;
	char			*src_start;
	unsigned int	dst_length;
	unsigned int	remaing;

	dst = dest;
	src_start = (char *)src;
	remaing = dstsize;
	while (remaing-- != 0 && *dst != '\0')
		dst++;
	dst_length = dst - dest;
	remaing = dstsize - dst_length;
	if (remaing == 0)
		return (dst_length + ft_strlen(src));
	while (*src != '\0')
	{
		if (remaing > 1)
		{
			*dst++ = *src;
			remaing--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_length + (src - src_start));
}
