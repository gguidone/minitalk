/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:36:46 by gguidone          #+#    #+#             */
/*   Updated: 2023/02/21 12:02:45 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if ((unsigned char )s1[i] < (unsigned char )s2[i])
			return (-1);
		else if ((unsigned char )s1[i] > (unsigned char )s2[i])
			return (1);
		else if ((unsigned char )s1[i] == 0 && (unsigned char )s2[i] == 0)
			return (0);
		i++;
	}
	return (0);
}
