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

t_message_info	g_minfo;

void	sned_bit(void);

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (g_minfo.server_pid == info->si_pid)
		sned_bit();
}

void	sned_bit(void)
{
	int	pre_bin_cur;
	int	pre_char_cur;

	if (g_minfo.message[g_minfo.char_cur] == 0)
	{
		g_minfo.exit_flag = 0;
		return ;
	}
	pre_bin_cur = g_minfo.binary_cur;
	pre_char_cur = g_minfo.char_cur;
	g_minfo.binary_cur -= 1;
	if (g_minfo.binary_cur == -1)
	{
		g_minfo.char_cur += 1;
		g_minfo.binary_cur = 7;
	}
	usleep(50);
	if (((g_minfo.message[pre_char_cur] >> pre_bin_cur) & 1) == 0)
		kill(g_minfo.server_pid, SIGUSR1);
	else
		kill(g_minfo.server_pid, SIGUSR2);
}

void	is_str_only_number(char *str)
{
	int	cur;

	cur = 0;
	while (str[cur])
	{
		if (!(str[cur] >= '0' && str[cur] <= '9'))
			exit(-1);
		cur += 1;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;

	if (argc != 3)
		exit(-1);
	is_str_only_number(argv[1]);
	g_minfo.exit_flag = 1;
	g_minfo.server_pid = ft_atoi(argv[1]);
	g_minfo.char_cur = 0;
	g_minfo.binary_cur = 7;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	g_minfo.message = argv[2];
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	sned_bit();
	while (g_minfo.exit_flag)
		pause();
	return (0);
}
