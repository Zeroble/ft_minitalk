/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:42:12 by minylee           #+#    #+#             */
/*   Updated: 2023/04/19 13:42:12 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int	flag;
	int	server_pid;
	int	cur = 0;
	int	cur2;

	if (argc != 3)
		exit(-1);
	server_pid = ft_atoi(argv[1], &flag);
	while (argv[2][cur] != 0)
	{
		cur2 = 7;
		// printf("\n%c", argv[2][cur]);
		while (cur2 >= 0)
		{
			if (((argv[2][cur] >> cur2 ) & 1) == 0)
			{
				kill(server_pid, SIGUSR1);
				// printf("0");
			}
			else
			{
				kill(server_pid, SIGUSR2);
				// printf("1");
			}
			usleep(100);
			cur2 -= 1;
		}
		cur += 1;
	}
	return (0);
}
