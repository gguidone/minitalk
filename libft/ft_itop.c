/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:00:07 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/27 16:17:35 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lene(unsigned long n)
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

char	converter(unsigned int r, char c)
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

char	*ft_itoeu(unsigned long n, char c)
{
	char	*s;
	int		i;

	i = lene(n);
	s = malloc(lene(n) + 1);
	if (!s)
		return (NULL);
	s[i] = 0;
	i--;
	while (i >= 0)
	{		
		s[i] = converter (n % 16, c);
		n = n / 16;
		i--;
	}
	return (s);
}

char	*ft_itop(unsigned long n)
{
	char	*s;
	char	*res;

	s = ft_itoeu(n, 'x');
	res = ft_strjoin("0x", s);
	free(s);
	return (res);
}
