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

int	main(int argc, char const *argv[])
{
	int	flag;
	int	server_pid;
	int	cur;
	int	binary_cur;

	if (argc != 3)
		exit(-1);
	cur = 0;
	server_pid = ft_atoi(argv[1], &flag);
	while (argv[2][cur] != 0)
	{
		binary_cur = 7;
		while (binary_cur >= 0)
		{
			if (((argv[2][cur] >> binary_cur) & 1) == 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(100);
			binary_cur -= 1;
		}
		cur += 1;
	}
	return (0);
}
