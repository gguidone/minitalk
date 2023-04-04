/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:54:33 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/27 16:17:33 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	leno(unsigned int n)
{
	int	cont;

	cont = 1;
	while (n / 8)
	{
		n = n / 8;
		cont++;
	}
	return (cont);
}

char	*ft_itoo(unsigned int n)
{
	char	*s;
	int		i;

	i = leno(n);
	s = malloc(leno(n) + 1);
	if (!s)
		return (NULL);
	s[i] = 0;
	i--;
	while (i >= 0)
	{		
		s[i] = (n % 8) + '0';
		n = n / 8;
		i--;
	}
	return (s);
}
