/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:33:07 by qrolande          #+#    #+#             */
/*   Updated: 2021/11/17 21:15:22 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

long	give_me_time(void)
{
	long			res;
	struct timeval	time_value;

	gettimeofday(&time_value, NULL);
	res = ((time_value.tv_sec * 1000)
			+ (time_value.tv_usec / 1000));
	return (res);
}

long	take_ms(struct timeval current)
{
	struct timeval	new_struct;
	long			res;

	res = 0;
	gettimeofday(&new_struct, NULL);
	new_struct.tv_usec -= current.tv_usec;
	new_struct.tv_sec -= current.tv_sec;
	if (new_struct.tv_usec < 0)
	{
		new_struct.tv_usec += 1000000;
		new_struct.tv_sec -= 1;
	}
	res = (new_struct.tv_sec * 1000) + (new_struct.tv_usec / 1000);
	return (res);
}

void	take_usleep(t_philosophers *ph, long action_time, struct timeval curr)
{
	long	time_now;

	time_now = take_ms(curr);
	while (1)
	{
		usleep(200);
		if (ph->strct->already_dead == DIED
			|| take_ms(curr) >= time_now + action_time)
			break ;
	}
}
