/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:25:28 by qrolande          #+#    #+#             */
/*   Updated: 2021/12/05 13:31:58 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static int	init_check(t_struct *start)
{
	if (start->num_of_philo == -1 || start->die_time == -1 \
		|| start->eat_time == -1 || start->sleep_time == -1 \
		|| start->eat_count == -1)
		return (-1);
	if (start->num_of_philo == 0 || start->num_of_philo > 200)
	{
		printf("There should be from 1 to 200\n");
		return (-1);
	}
	if (start->eat_count == 0)
	{
		printf("Feed the philosophers at least once\n");
		return (-1);
	}
	return (0);
}

static int	init_struct(t_struct *start, char **av, int ac)
{
	start->num_of_philo = modif_atoi(av[1]);
	start->die_time = modif_atoi(av[2]);
	start->eat_time = modif_atoi(av[3]);
	start->sleep_time = modif_atoi(av[4]);
	start->already_dead = 1;
	start->eat_count = -2;
	if (ac == 6)
		start->eat_count = modif_atoi(av[5]);
	if (init_check(start) == -1)
		return (-1);
	return (0);
}

static void	endgame(t_struct *start)
{
	int	i;

	i = 0;
	check_status(start);
	usleep(200);
	while (i < start->num_of_philo)
	{
		pthread_mutex_destroy(&start->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&start->print);
}

int	main(int ac, char **av)
{
	t_struct	start;

	if (ac == 5 || ac == 6)
	{
		if (init_struct(&start, av, ac) == -1)
			return (-1);
		start.mutex = malloc(sizeof(pthread_mutex_t) * start.num_of_philo);
		start.ph = malloc(sizeof(t_philosophers) * start.num_of_philo);
		if (!start.ph || !start.ph)
		{
			printf("Oops, can't allocate memory\n");
			return (-1);
		}
		if (begin(&start) == -1)
			return (-1);
		endgame(&start);
	}
	else
	{
		printf("5 or 6 arguments needed\n");
		return (-1);
	}
	return (0);
}
