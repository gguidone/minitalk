/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:21:21 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/27 16:17:31 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenp(unsigned int n)
{
	int	cont;

	cont = 1;
	while (n / 16)
	{
		n = n / 16;
		cont++;
	}
	return (cont);
}

char	converterp(unsigned int r, char c)
{
	int	sum;

	sum = 0;
	if (c == 'X')
		sum = -32;
	if (r < 10)
		return (r + '0');
	else if (r == 10)
		return ('a' + sum);
	else if (r == 11)
		return ('b' + sum);
	else if (r == 12)
		return ('c' + sum);
	else if (r == 13)
		return ('d' + sum);
	else if (r == 14)
		return ('e' + sum);
	else
		return ('f' + sum);
}

char	*ft_itoe(unsigned int n, char c)
{
	char	*s;
	int		i;

	i = lenp(n);
	s = malloc(lenp(n) + 1);
	if (!s)
		return (NULL);
	s[i] = 0;
	i--;
	while (i >= 0)
	{		
		s[i] = converterp(n % 16, c);
		n = n / 16;
		i--;
	}
	return (s);
}
