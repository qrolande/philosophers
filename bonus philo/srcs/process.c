/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:49:37 by qrolande          #+#    #+#             */
/*   Updated: 2021/12/07 19:56:31 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/bonus_philo.h"

static void	*if_death(void *x)
{
	t_struct	*temp;

	temp = (t_struct *)x;
	pthread_detach(temp->thread);
	while (1)
	{
		if (give_me_time() - temp->ph->lasteat > temp->ph->die_time)
		{
			if (temp->ph->num == 1)
				sem_post(temp->dead);
			sem_wait(temp->print);
			printf(RED"%ld Philo %d DIED\n", take_ms(temp->philo_time), \
				temp->ph->num);
		}
	}
}

static void	console_print_forks(t_struct *start, int value)
{
	if (value == L_FORK)
	{
		sem_wait(start->print);
		printf("%ld Philo %d took left fork\n", take_ms(start->philo_time),
			start->ph->num + 1);
		sem_post(start->print);
	}
	if (value == R_FORK)
	{
		sem_wait(start->print);
		printf("%ld Philo %d took right fork\n", take_ms(start->philo_time),
			start->ph->num + 1);
		sem_post(start->print);
	}
}

static void	console_print(t_struct *start, int value)
{
	if (value == EAT)
	{
		sem_wait(start->print);
		printf("%ld Philo %d eating\n", take_ms(start->philo_time),
			start->ph->num + 1);
		sem_post(start->print);
	}
	if (value == SLEEP)
	{
		sem_wait(start->print);
		printf("%ld Philo %d sleeping\n", take_ms(start->philo_time),
			start->ph->num + 1);
		sem_post(start->print);
	}
	if (value == THINK)
	{
		sem_wait(start->print);
		printf("%ld Philo %d thinking\n", take_ms(start->philo_time),
			start->ph->num + 1);
		sem_post(start->print);
	}
}

int	philo_lunch(t_struct *start)
{
	start->ph->lasteat = start->ph->zero_time;
	pthread_create(&start->thread, NULL, if_death, (void *)start);
	while (start->ph->eat_count != 0)
	{
		sem_wait(start->forks);
		sem_wait(start->feded);
		console_print_forks(start, L_FORK);
		sem_wait(start->feded);
		console_print_forks(start, R_FORK);
		sem_post(start->forks);
		start->ph->lasteat = give_me_time();
		console_print(start, EAT);
		gettimeofday(&start->current, NULL);
		take_usleep(start->ph->eat_time, start->current);
		sem_post(start->feded);
		sem_post(start->feded);
		console_print(start, SLEEP);
		gettimeofday(&start->current, NULL);
		take_usleep(start->ph->eat_time, start->current);
		console_print(start, THINK);
		start->ph->eat_count--;
	}
	exit (1);
}
