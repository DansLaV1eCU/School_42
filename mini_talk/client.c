/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:47 by llupache          #+#    #+#             */
/*   Updated: 2024/10/27 18:09:09 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

void	signal_handler(int signum)
{
	printf("Received %d!/n", signum);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int		count_minus;
	int		count;
	int		result;
	char	*str1;

	str1 = (char *)str;
	count_minus = 1;
	count = 0;
	result = 0;
	while (((str1[count] >= 9 && str1[count] <= 13) || str1[count] == 32))
		count++;
	if (str1[count] == '-' || str1[count] == '+')
	{
		if (str1[count + 1] < '0' || str1[count + 1] > '9')
			return (0);
		else if (str1[count] == '-')
			count_minus = -1;
		count++;
	}
	while (str1[count] >= '0' && str1[count] <= '9')
	{
		result = result * 10 + (str1[count] - '0');
		count++;
	}
	return (result * count_minus);
}

void send_message(int pid, char c)
{
	int i;
	int bit;
	char temp;

	i = 8;
	temp = c;
	while (i)
	{
		bit = temp >> i & 1;
		kill(pid, bit);
		printf("%d", bit);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int i;
	char *str;

	if (argc != 3)
		return (printf("Error"));
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (printf("Error"));
	str = argv[2];
	i = 0;
	while(str[i])
		send_message(pid, str[i++]);
	return (0);
}
