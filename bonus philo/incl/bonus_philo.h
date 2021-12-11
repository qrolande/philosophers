/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolande <qrolande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:24:18 by qrolande          #+#    #+#             */
/*   Updated: 2021/12/07 19:52:54 by qrolande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PHILO_H
# define BONUS_PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <signal.h>

# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"

# define MAX_INT 2147483647
# define DIED 	0
# define EAT 	1
# define SLEEP	2
# define THINK	3
# define L_FORK	4
# define R_FORK	5

typedef struct s_philosophers
{
	int				num_of_philo;
	int				num;
	int				eat_time;
	int				sleep_time;
	int				die_time;
	int				eat_count;
	int				already_dead;
	long			zero_time;
	long			lasteat;
}				t_philosophers;

typedef struct s_struct
{
	int				*philo;
	pthread_t		thread;
	pthread_t		thread_meal;
	sem_t			*feded;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*dead;
	t_philosophers	*ph;
	struct timeval	current;
	struct timeval	philo_time;
}					t_struct;

void	print_error(int flag);
int		modif_atoi(char *str);
int		philo_lunch(t_struct *start);
void	semclose(t_struct *start);
void	begin(t_struct *start);
void	take_usleep(long action_time, struct timeval curr);
long	take_ms(struct timeval current);
long	give_me_time(void);
void	if_all_eat(t_struct *start);

#endif
