/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:24:18 by qrolande          #+#    #+#             */
/*   Updated: 2021/12/05 13:33:16 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"

# define MAX_INT 2147483647
# define DIED 	0
# define EAT 	1
# define SLEEP	2
# define THINK	3
# define FORKS	4

typedef struct s_philosophers
{
	int				left_fork;
	int				right_fork;
	int				mutex_num;
	int				each_philo_eat_count;
	long			last_meal;
	pthread_t		thread;
	struct s_struct	*strct;
}				t_philosophers;

typedef struct s_struct
{
	int				num_of_philo;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				eat_count;
	int				already_dead;
	long			zero_time;
	t_philosophers	*ph;
	struct timeval	current;
	struct timeval	philo_time;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
}				t_struct;

long	give_me_time(void);
void	*simulation(void *x);
int		modif_atoi(char *str);
int		begin(t_struct *start);
int		thread_init(t_struct *start);
void	check_status(t_struct *start);
int		philo_lunch(t_philosophers *ph);
long	take_ms(struct timeval current);
void	take_usleep(t_philosophers *ph, long action_time, struct timeval curr);

#endif
