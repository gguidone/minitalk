/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguidone <gguidone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:33:06 by gguidone          #+#    #+#             */
/*   Updated: 2023/03/13 16:33:06 by gguidone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_errors(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (1);
	while (argv[1][i])
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static void	send_len(int len, int pid)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(100);
	}
}

static void	send_char(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*to_send;
	int		len;
	int		i;

	if (check_errors(argc, argv))
	{
		ft_printf("Errore");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	to_send = argv[2];
	len = ft_strlen(to_send);
	send_len(len, pid);
	i = -1;
	while (to_send[++i])
		send_char(to_send[i], pid);
	send_char(to_send[i], pid);
}
