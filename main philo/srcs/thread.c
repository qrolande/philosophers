/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:10:54 by qrolande          #+#    #+#             */
/*   Updated: 2021/11/27 12:54:46 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	*simulation(void *x)
{
	t_philosophers	*ph;

	ph = (t_philosophers *)x;
	pthread_detach(ph->thread);
	ph->last_meal = ph->strct->zero_time;
	while (1)
	{
		if (philo_lunch(ph) == -1)
			break ;
	}
	return (NULL);
}

int	thread_init(t_struct *start)
{
	int	i;

	i = 0;
	while (++i <= start->num_of_philo)
	{
		if (i % 2 != 0)
		{
			if (pthread_create(&start->ph[i - 1].thread, NULL,
					simulation, (void *)&start->ph[i - 1]) != 0)
				return (-1);
			usleep(20);
		}
		else
		{
			if (pthread_create(&start->ph[i - 1].thread, NULL,
					simulation, (void *)&start->ph[i - 1]) != 0)
				return (-1);
			usleep(20);
		}
	}
	return (0);
}
