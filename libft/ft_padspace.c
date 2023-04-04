/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:24:08 by gguidone          #+#    #+#             */
/*   Updated: 2023/02/28 10:24:08 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*tostr(const char *format, va_list params)
{
	char	*s;

	s = 0;
	if (*format == 's' || *format == 'S')
		s = ft_strdup(va_arg(params, char *));
	if (*format == 'd' || *format == 'i')
		s = ft_itoa(va_arg(params, int));
	if (*format == 'o' || *format == 'u'
		|| *format == 'x' || *format == 'X')
		s = ft_itox(va_arg(params, unsigned int), *format);
	if (*format == 'c' || *format == 'C')
	{
		s = malloc(2);
		s[0] = va_arg(params, int);
		s[1] = 0;
	}
	if (*format == 'p')
		s = ft_itop(va_arg(params, unsigned int));
	return (s);
}

int	fnpad(char *s, const char *format, int n, int precision)
{
	int	npad;

	if (!(*format == 's' || *format == 'S'))
		npad = n - ft_strlen(s);
	else
		npad = n - precision;
	return (npad);
}

const char	*precision_w_space(const char *format, int *precision)
{
	if (*format == '.')
	{
		format++;
		*precision = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	else
		*precision = 0;
	return (format);
}

void	ft_padspace(const char *format, va_list params, char c, int *count)
{
	int		n;
	int		precision;
	char	*s;
	int		npad;

	n = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	format = precision_w_space(format, &precision);
	s = tostr(format, params);
	npad = fnpad(s, format, n, precision);
	if (npad > 0 && c == 'l')
		while (npad--)
			*count += ft_putchar(' ');
	if (!(*format == 's' || *format == 'S'))
		*count += ft_putstr(s);
	else
	{
		while (precision--)
			*count += ft_putchar(*s++);
		free(s);
	}
	if (npad > 0 && c == 'r')
		while (npad--)
			*count += ft_putchar(' ');
}

void	ft_padzero(const char *format, va_list params, char c, int *count)
{
	int		n;
	char	*s;
	int		npad;

	n = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	s = tostr(format, params);
	npad = n - ft_strlen(s);
	if (npad > 0 && c == 'l')
		while (npad--)
			*count += ft_putchar('0');
	*count += ft_putstr(s);
	if (npad > 0 && c == 'r')
		while (npad--)
			*count += ft_putchar('0');
}
