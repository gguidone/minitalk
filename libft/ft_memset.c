/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:05:01 by gguidone          #+#    #+#             */
/*   Updated: 2023/02/28 09:55:05 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char			*p;
	unsigned char	cr;

	p = str;
	cr = (unsigned char) c;
	while (n > 0)
	{
		*p++ = cr;
		n--;
	}
	return (str);
}
