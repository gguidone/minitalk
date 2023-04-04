/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:17:05 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/27 16:16:36 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*set_null(char *s)
{
	s = malloc(7);
	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	s[6] = 0;
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;

	i = 0;
	s = NULL;
	if (!s1)
	{
		s = set_null(s);
		return (s);
	}
	s = malloc(ft_strlen(s1) + 1);
	if (s == NULL)
		return (s);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
