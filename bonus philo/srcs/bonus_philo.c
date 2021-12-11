/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:13:28 by qrolande          #+#    #+#             */
/*   Updated: 2021/12/07 19:53:28 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/bonus_philo.h"

static void	init_struct(t_struct *start, char **av, int ac)
{
	start->ph->num_of_philo = modif_atoi(av[1]);
	start->ph->die_time = modif_atoi(av[2]);
	start->ph->eat_time = modif_atoi(av[3]);
	start->ph->sleep_time = modif_atoi(av[4]);
	start->ph->already_dead = 1;
	start->ph->num = 1;
	start->ph->eat_count = -2;
	if (ac == 6)
	{
		start->ph->eat_count = modif_atoi(av[5]);
		if (start->ph->eat_count == 0)
			print_error(2);
	}
	if (start->ph->num_of_philo < 1 || start->ph->num_of_philo > 200)
		print_error(3);
	sem_unlink("Feded");
	sem_unlink("Forks");
	sem_unlink("Dead");
	sem_unlink("Printing");
	start->feded = sem_open("Feded", O_CREAT, 0666, start->ph->num_of_philo);
	start->forks = sem_open("Forks", O_CREAT, 0666, start->ph->num_of_philo);
	start->dead = sem_open("Dead", O_CREAT, 0666, 1);
	start->print = sem_open("Printing", O_CREAT, 0666, 1);
}

int	main(int ac, char **av)
{
	t_struct	start;
	int			philo_num;

	if (ac == 5 || ac == 6)
	{
		philo_num = modif_atoi(av[1]);
		start.philo = malloc(sizeof(int) * philo_num);
		start.ph = malloc(sizeof(t_philosophers) * philo_num);
		if (start.ph == NULL || start.philo == NULL)
			print_error(4);
		init_struct(&start, av, ac);
		begin(&start);
		usleep(200);
		if (ac == 6)
			if_all_eat(&start);
		sem_wait(start.dead);
		start.dead = 0;
		while (--philo_num >= 0)
			kill(start.philo[philo_num], SIGKILL);
		semclose(&start);
	}	
	else
		print_error(1);
	return (0);
}
