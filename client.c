/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:53:05 by mgarabei          #+#    #+#             */
/*   Updated: 2024/01/06 15:02:44 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_msg(int pid, char *msg, size_t len)
{
	int		bit;
	size_t	letter;

	letter = 0;
	while (letter <= len)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((msg[letter] >> bit & 1) == 0)
				kill(pid, SIGUSR1);
			else if ((msg[letter] >> bit & 1) == 1)
				kill(pid, SIGUSR2);
			bit++;
			usleep(420);
		}
		letter++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 1000)
		{
			ft_printf("PID is not valid!");
			return (0);
		}
		if (!pid)
		{
			ft_printf("Make sure that the first argument is the server's PID!");
			return (0);
		}
		msg = argv[2];
		if (msg[0] == '\0')
			ft_printf("Make sure you have sent a message!");
		send_msg(pid, msg, ft_strlen(msg));
	}
	else
		ft_printf("Wrong number of arguments!");
	return (0);
}
