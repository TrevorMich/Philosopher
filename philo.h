/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:19:09 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/26 12:35:03 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

# define EAT "is eating"
# define THINK "is thinking"
# define FORK "has picked up a fork"
# define SLEEP "is sleeping"
# define DIED "died"

typedef struct s_data
{
	int				num_philo;
	int				t_eat;
	int				t_die;
	int				t_sleep;
	int				philo_died;
	int				num_eat;
	long long		time;
	pthread_t		monitor;
	pthread_mutex_t	mem_shared;
	pthread_mutex_t	print;
	pthread_mutex_t	*ph_mutex;
	pthread_mutex_t	tm;
}	t_data;

typedef struct s_philo
{
	int			id;
	pthread_t	th;
	int			num_eaten;
	long long	t_die;
	int			l_fork;
	int			r_fork;
	t_data		*data;	
}	t_philo;

int			checks(int argc, char **argv);
int			ft_atoi(const char *str);
int			init_data(t_data *data, char **argv, int argc);
void		init_philo(t_philo *philo, t_data *data);
int			ft_isdigit(int digit);
int			its_dead(t_philo *philo, int *i);
int			create_thread(t_philo *philo);
int			simulation(t_philo *philo);
int			philo_sleep(t_philo *philo);
int			philo_think(t_philo *philo);
void		help_routine2(t_philo *philo);
void		one_philo(t_data *data, t_philo *philo);
void		help_routine1(t_philo *philo);
void		help2_routine1(t_philo *philo);
void		help2_routine2(t_philo *philo);
void		free_all(t_data *data, t_philo *philo);
void		*routine2(void *arg);
void		*routine2(void *arg);
void		time_sim(long long time);
int			philo_eat(t_philo *philo);
int			print_state(t_philo *philo, int id, char *color, char *status);
long long	get_time(void);
long long	time_diff(long long time);
void		d_forks(t_philo *philo, int flag);
#endif