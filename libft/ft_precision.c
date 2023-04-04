/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:02:54 by gguidone          #+#    #+#             */
/*   Updated: 2023/02/28 16:02:54 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_precision(const char *format, va_list params)
{
	int		n;
	char	*s;
	int		count;

	count = 0;
	n = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	if (*format == 's' || *format == 'S')
	{
		s = va_arg(params, char *);
		while (n-- && *s)
			count += ft_putchar(*s++);
	}
	if (*format == 'd' || *format == 'i')
		count += ft_putstr(ft_itoa(va_arg(params, int)));
	if (*format == 'o' || *format == 'u'
		|| *format == 'x' || *format == 'X')
		count += ft_putstr (ft_itox(va_arg(params, unsigned int), *format));
	if (*format == 'c' || *format == 'C')
		count += ft_putchar(va_arg(params, int));
	return (count);
}
