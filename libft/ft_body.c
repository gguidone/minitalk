/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:33:37 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/27 16:17:56 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*check_(const char *format, va_list params, int *count)
{
	if (*format == '-')
	{
		format++;
		if (*format >= '1' && *format <= '9')
		{
			ft_padspace(format, params, 'r', count);
			format = jump(format);
		}
		if (*format == '0')
		{
			ft_padzero(format, params, 'r', count);
			format = jump(format);
		}
		format = jump(format);
	}
	return (format);
}

const char	*checkhash(const char *format, va_list params, int *count)
{
	format++;
	if (*format == 'o')
	{
		*count += ft_putchar('0');
		*count += ft_putstr(ft_itoo(va_arg(params, int)));
	}
	else if (*format == 'x')
	{
		*count += ft_putchar('0');
		*count += ft_putchar('x');
		*count += ft_putstr(ft_itox(va_arg(params, int), 'x'));
	}
	else if (*format == 'X')
	{
		*count += ft_putchar('0');
		*count += ft_putchar('X');
		*count += ft_putstr(ft_itox(va_arg(params, int), 'X'));
	}
	return (format);
}

const char	*checkkeys(const char *format, va_list params, int *count)
{
	if (*format == '#')
		format = checkhash(format, params, count);
	else
	{
		if (*format == 's' || *format == 'S')
			*count += ft_putstr(ft_strdup(va_arg(params, char *)));
		if (*format == 'd' || *format == 'i')
			*count += ft_putstr(ft_itoa(va_arg(params, int)));
		if (*format == 'x' || *format == 'X' || *format == 'u')
			*count += ft_putstr(ft_itox(va_arg(params, unsigned int), *format));
		if (*format == 'c' || *format == 'C')
			*count += ft_putchar(va_arg(params, int));
		if (*format == 'p')
			*count += ft_putstr(ft_itop(va_arg(params, unsigned long)));
	}
	return (format);
}

const char	*format_is_percent_2(const char *f, va_list params, int *count)
{
	if (*f == '0')
	{
		ft_padzero(f, params, 'l', count);
		f = jump(f);
	}
	f = check_(f, params, count);
	if (*f == '.')
	{
		f++;
		*count += ft_precision(f, params);
		f = jump(f);
	}
	return (f);
}

const char	*format_is_percent(const char *format, va_list params, int *count)
{
	format++;
	if (*format == '+')
	{
		format++;
		*count += ft_putstr(ft_itoaplus(va_arg(params, int)));
		format++;
	}
	format = checkkeys(format, params, count);
	if (*format == '%')
		*count += ft_putchar(*format);
	if (*format >= '1' && *format <= '9')
	{
		ft_padspace(format, params, 'l', count);
		format = jump(format);
	}
	format = format_is_percent_2(format, params, count);
	return (format);
}
