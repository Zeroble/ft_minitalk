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

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	convert_base(int number, char *obases, char obase);
int	print_number(int number, char *obases, char obase);

void	set_bit(char *recive_bits, short value)
{
	static int	idx = 7;

	if (idx == -1)
		idx = 7;
	if (value == 1)
		(*recive_bits) |= (1 << idx);
	else
		(*recive_bits) &= ~(1 << idx);
	if (idx == 0)
		write(1, recive_bits, 1);
	idx -= 1;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	recive_bits;

	(void)context;
	if (sig == SIGUSR1)
		set_bit(&recive_bits, 0);
	else if (sig == SIGUSR2)
		set_bit(&recive_bits, 1);
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
