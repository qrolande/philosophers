/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:03:21 by qrolande          #+#    #+#             */
/*   Updated: 2021/11/24 18:39:59 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static void	fork_init(t_struct *start)
{
	int	i;

	i = 0;
	while (i <= start->num_of_philo)
	{
		start->ph[i].left_fork = i;
		if ((i) % start->num_of_philo != 0)
			start->ph[i].right_fork = i + 1;
		else
			start->ph[i].right_fork = (i + 1) % start->num_of_philo;
		i++;
	}
}

static int	mutex_init(t_struct *start)
{
	int	i;

	i = 0;
	while (i < start->num_of_philo)
	{
		if (pthread_mutex_init(&start->mutex[i], NULL) != 0)
		{
			printf("Error, can't create mutex\n");
			return (-1);
		}
		start->ph[i].mutex_num = i + 1;
		start->ph[i].strct = start;
		i++;
	}
	if (pthread_mutex_init(&start->print, NULL) != 0)
	{
		printf("Error, can't create mutex\n");
		return (-1);
	}
	return (0);
}

int	begin(t_struct *start)
{
	int	i;

	i = 0;
	while (++i <= start->num_of_philo)
		start->ph[i - 1].each_philo_eat_count = start->eat_count;
	fork_init(start);
	if (mutex_init(start) == -1)
		return (-1);
	gettimeofday(&start->philo_time, NULL);
	start->zero_time = give_me_time();
	if (thread_init(start) == -1)
	{
		printf("Error: Cant create thread.\n");
		free(start->ph);
		return (-1);
	}
	return (0);
}
