/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:12:28 by minylee           #+#    #+#             */
/*   Updated: 2023/04/18 15:12:28 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

char	g_revive_char;

int	convert_base(int number, char *obases, char obase);
int	print_number(int number, char *obases, char obase);

void	set_bit(char *ptr, short value)
{
	static int	idx = 7;

	if (idx == -1)
		idx = 7;
	if (value == 1)
		(*ptr) |= (1 << idx);
	else
		(*ptr) &= ~(1 << idx);
	if (idx == 0)
		write(1, &g_revive_char, 1);
	idx -= 1;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		set_bit(&g_revive_char, 0);
	else if (sig == SIGUSR2)
		set_bit(&g_revive_char, 1);
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	print_number(getpid(), "0123456789", 10);
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	write(1, "\n", 1);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
}

int	convert_base(int number, char *obases, char obase)
{
	int	ret;

	ret = 0;
	if (number / obase == 0)
	{
		ret += write(1, &obases[number], 1);
		return (ret);
	}
	else
	{
		ret = convert_base(number / obase, obases, obase);
		ret += write(1, &obases[number % obase], 1);
		return (ret);
	}
}

int	print_number(int number, char *obases, char obase)
{
	int	ret;

	ret = 0;
	if (number == -2147483648)
	{
		ret = write(1, "–2147483648\n", 12);
		return (ret);
	}
	else if (number < 0)
	{
		ret = write(1, "-", 1);
		number *= -1;
	}
	ret += convert_base(number, obases, obase);
	return (ret);
}
