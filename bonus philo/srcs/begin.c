/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:30:18 by qrolande          #+#    #+#             */
/*   Updated: 2021/12/07 19:56:11 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/bonus_philo.h"

void	semclose(t_struct *start)
{
	sem_unlink("Feded");
	sem_unlink("Forks");
	sem_unlink("Dead");
	sem_unlink("Printing");
	sem_close(start->feded);
	sem_close(start->forks);
	sem_close(start->print);
	sem_post(start->dead);
	sem_close(start->dead);
}

static void	*all_eat(void *eat)
{
	t_struct	*temp;
	int			i;

	i = 0;
	temp = (t_struct *)eat;
	i = temp->ph->num_of_philo - 1;
	while (i >= 0)
	{
		waitpid(temp->philo[i], 0, 0);
		i--;
	}
	if (temp->ph->already_dead == DIED)
		return (NULL);
	printf(GREEN"%ld  Everyone ate %d times\n", take_ms(temp->philo_time),
		temp->ph->eat_count);
	semclose(temp);
	exit (1);
}

void	if_all_eat(t_struct *start)
{
	pthread_create(&start->thread_meal, NULL, all_eat, (void *)start);
	pthread_detach(start->thread_meal);
}

void	begin(t_struct *start)
{
	int	i;

	i = -1;
	start->ph->zero_time = give_me_time();
	gettimeofday(&start->philo_time, NULL);
	while (++i < start->ph->num_of_philo)
	{
		start->ph->num = i;
		start->philo[i] = fork();
		if (start->philo[i] == 0)
		{
			if (i == 0)
				sem_wait(start->dead);
			philo_lunch(start);
		}
		usleep(100);
	}
}
