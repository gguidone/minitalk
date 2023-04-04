/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:13:18 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/27 16:16:27 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*jump(const char *format)
{
	while (!(*format == 's' || *format == 'S' || *format == 'd'
			|| *format == 'i' || *format == 'o' || *format == 'u'
			|| *format == 'x' || *format == 'X' || *format == 'c'
			|| *format == 'C'))
		format++;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		count;

	count = 0;
	va_start(params, format);
	while (*format)
	{
		if (*format == '%')
			format = format_is_percent(format, params, &count);
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(params);
	return (count);
}
