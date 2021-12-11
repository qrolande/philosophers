/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:49:37 by qrolande          #+#    #+#             */
/*   Updated: 2021/11/23 22:47:07 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void	console_print_forks(t_philosophers *ph, int value)
{	
	if (value == FORKS)
	{
		pthread_mutex_lock(&ph->strct->print);
		printf("%ld Philo %d has taken forks\n", take_ms(ph->strct->philo_time),
			ph->mutex_num);
		pthread_mutex_unlock(&ph->strct->print);
	}
}

static void	console_print(t_philosophers *ph, int value)
{
	if (value == EAT)
	{
		pthread_mutex_lock(&ph->strct->print);
		printf("%ld Philo %d eating\n", take_ms(ph->strct->philo_time), \
			ph->mutex_num);
		pthread_mutex_unlock(&ph->strct->print);
	}
	else if (value == SLEEP)
	{
		pthread_mutex_lock(&ph->strct->print);
		printf("%ld Philo %d sleeping\n", take_ms(ph->strct->philo_time), \
			ph->mutex_num);
		pthread_mutex_unlock(&ph->strct->print);
	}
	else if (value == THINK)
	{
		pthread_mutex_lock(&ph->strct->print);
		printf("%ld Philo %d thinking\n", take_ms(ph->strct->philo_time), \
			ph->mutex_num);
		pthread_mutex_unlock(&ph->strct->print);
	}
}

static void	take_forks(t_philosophers *ph)
{
	pthread_mutex_lock(&ph->strct->mutex[ph->left_fork]);
	pthread_mutex_lock(&ph->strct->mutex[ph->right_fork]);
	console_print_forks(ph, FORKS);
}

int	philo_lunch(t_philosophers *ph)
{
	if (ph->strct->already_dead == DIED)
		return (-1);
	take_forks(ph);
	if (ph->strct->already_dead == DIED)
		return (-1);
	ph->last_meal = give_me_time();
	console_print(ph, EAT);
	gettimeofday(&ph->strct->current, NULL);
	take_usleep(ph, ph->strct->eat_time, ph->strct->current);
	pthread_mutex_unlock(&ph->strct->mutex[ph->left_fork]);
	pthread_mutex_unlock(&ph->strct->mutex[ph->right_fork]);
	if (ph->strct->already_dead == DIED)
		return (-1);
	if (ph->each_philo_eat_count != 0)
		ph->each_philo_eat_count -= 1;
	gettimeofday(&ph->strct->current, NULL);
	console_print(ph, SLEEP);
	take_usleep(ph, ph->strct->sleep_time, ph->strct->current);
	if (ph->strct->already_dead == DIED)
		return (-1);
	console_print(ph, THINK);
	return (0);
}
