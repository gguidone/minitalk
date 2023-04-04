/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:27:22 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/13 16:27:22 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long	power(int base, int exp)
{
	long	r;
	int		lsb;

	lsb = 0;
	r = 1;
	while (exp > 0)
	{
		lsb = exp & 0x1;
		if (lsb)
			r *= base;
		base *= base;
		exp >>= 1;
	}
	return (r);
}

static void	rec_len(int *curr_bit, char **str, int *received, int s)
{
	static int	len_val = 0;

	if (s == SIGUSR2)
		len_val += power(2, *curr_bit);
	if (*curr_bit == 31)
	{
		*received = 1;
		*str = ft_calloc(len_val + 1, 1);
		*curr_bit = 0;
		len_val = 0;
		return ;
	}
	(*curr_bit)++;
}

static void	restart_var(int *len_received, char **str, int *i)
{
	*len_received = 0;
	if (str)
	{
		ft_putendl_fd(*str, 1);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

static void	receive(int signal)
{
	static int	char_value = 0;
	static int	curr_bit = 0;
	static int	len_received = 0;
	static int	i = 0;
	static char	*final_str = 0;

	if (!len_received)
		rec_len(&curr_bit, &final_str, &len_received, signal);
	else
	{
		if (signal == SIGUSR2)
			char_value += power(2, curr_bit);
		if (curr_bit == 7)
		{
			final_str[i++] = char_value;
			curr_bit = 0;
			if (char_value == 0)
				return (restart_var(&len_received, &final_str, &i));
			char_value = 0;
			return ;
		}
		curr_bit++;
	}
}

/*
** SIGUSR1 = 30 ---> defines the '0' bit
** SIGUSR2 = 31 --> defines the '1' bit
*/

int	main(void)
{
	int	id;

	id = (int) getpid();
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
		usleep(100);
}
