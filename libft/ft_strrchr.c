/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:31:49 by gguidone          #+#    #+#             */
/*   Updated: 2023/02/15 14:17:46 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	cr;

	i = ft_strlen(s);
	cr = (char) c;
	while (i >= 0)
	{
		if (s[i] == cr)
			return (&s[i]);
		i--;
	}
	return (0);
}
