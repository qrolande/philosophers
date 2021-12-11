/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:15:23 by qrolande          #+#    #+#             */
/*   Updated: 2021/11/23 22:51:55 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static int	if_somebody_dead(t_struct *start, int i)
{
	long	time;

	time = give_me_time();
	if (time - start->ph[i - 1].last_meal > start->die_time)
	{
		start->already_dead = 0;
		pthread_mutex_lock(&start->print);
		usleep(20);
		printf(RED"%ld  %d DIED\n", take_ms(start->philo_time), i);
		return (-1);
	}
	return (0);
}

static void	is_everyone_ate(t_struct *start)
{
	start->already_dead = 0;
	pthread_mutex_lock(&start->print);
	usleep(20);
	printf(GREEN"%ld  Everyone ate %d times\n", take_ms(start->philo_time),
		start->eat_count);
}

void	check_status(t_struct *start)
{
	int	value;
	int	i;

	value = 1;
	while (1)
	{
		i = 0;
		if (value != 0)
		{
			value = 0;
			while (++i <= start->num_of_philo)
			{
				value += start->ph[i - 1].each_philo_eat_count;
				if (if_somebody_dead(start, i) == -1)
					return ;
			}
		}
		else
		{
			is_everyone_ate(start);
			return ;
		}
	}
}
