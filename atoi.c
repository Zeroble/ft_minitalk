/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:15:59 by minylee           #+#    #+#             */
/*   Updated: 2023/04/14 05:36:10 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ascii_to_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (c - 48);
	else
		return (-1);
}

static int	set_sign(char c, int *sign)
{
	if (c == '-')
	{
		*sign = -1;
		return (1);
	}
	else if (c == '+')
	{
		return (1);
	}
	return (0);
}

static short	get_int_max_len(void)
{
	int		int_max;
	short	len;

	int_max = INT_MAX;
	len = 0;
	while (int_max != 0)
	{
		int_max /= 10;
		len += 1;
	}
	return (len);
}

int	ft_atoi(const char *c)
{
	long long	ret;
	int			tmp;
	int			sign;
	short		len;

	ret = 0;
	sign = 1;
	len = 0;
	while (ft_isspace(*c))
		c++;
	c += set_sign(*c, &sign);
	while (*c != 0 && *c >= '0' && *c <= '9')
	{
		tmp = ascii_to_digit(*c);
		ret *= 10;
		ret += tmp;
		len += 1;
		c += 1;
	}
	ret *= sign;
	if (len > get_int_max_len())
		exit(-1);
	if (!(ret >= INT_MIN && ret <= INT_MAX))
		exit(-1);
	return (sign * ret);
}
