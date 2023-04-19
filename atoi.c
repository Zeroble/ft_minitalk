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

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ascii_to_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (c - 48);
	else
		return (-1);
}

int	ft_atoi(const char *c, int *sign)
{
	int	ret;
	int	tmp;

	ret = 0;
	*sign = -1;
	while (ft_isspace(*c))
		c++;
	if (*c == '-')
	{
		*sign = 1;
		c++;
	}
	else if (*c == '+')
		c++;
	while (*c != 0 && ft_isdigit(*c))
	{
		tmp = ascii_to_digit(*c);
		ret *= 10;
		ret -= tmp;
		c++;
	}
	return (*sign * ret);
}
