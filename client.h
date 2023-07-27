/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minylee <minylee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:44:40 by minylee           #+#    #+#             */
/*   Updated: 2023/04/19 13:44:40 by minylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

typedef struct s_message_info
{
	int		binary_cur;
	int		char_cur;
	int		server_pid;
	short	exit_flag;
	char	*message;
}	t_message_info;

int	ft_atoi(const char *c);

#endif
