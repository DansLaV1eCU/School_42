/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:47 by llupache          #+#    #+#             */
/*   Updated: 2025/05/17 20:54:46 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		feedback = 1;

void	wait_feedback(void)
{
	int time;

	time = 10;
	while (feedback == 0 && time--)
	{
		usleep(1000);
	}
	if (feedback == 0)
	{
		ft_printf("Feedback ne byl poluchen");
		exit(0);
	}
}

void change_feedback(void)
{
	feedback = 1;
}

void	send_message(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (i < 8)
		{
			if (str[j] & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			
			wait_feedback();
			i++;
		}
		j++;
	}
	j = 0;
	while (j++ < 8)
	{
		kill(pid, SIGUSR2);
		feedback = 0;
		wait_feedback();
	}
}

int	main(int argc, char **argv)
{
	int					pid;

	if (argc != 3)
		return (ft_printf("Error"));
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Error"));
	signal(SIGUSR2, change_feedback);
	send_message(pid, argv[2]);
	return (0);
}
