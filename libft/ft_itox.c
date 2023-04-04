/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:35:24 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/27 16:17:40 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itox(unsigned int n, char c)
{
	if (c == 'o')
		return (ft_itoo(n));
	if (c == 'x' || c == 'X')
		return (ft_itoe(n, c));
	if (c == 'u')
		return (ft_itoau(n));
	return (NULL);
}
