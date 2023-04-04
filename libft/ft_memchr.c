/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:27:25 by gguidone          #+#    #+#             */
/*   Updated: 2023/02/17 13:50:30 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cr;
	int				i;
	char			*str;

	str = (char *)s;
	i = 0;
	cr = (unsigned char) c;
	while (n--)
	{
		if ((unsigned char)str[i] == cr)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
