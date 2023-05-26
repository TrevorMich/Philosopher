/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_todo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:31:42 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/25 10:39:07 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->ph_mutex[philo->l_fork]);
	if (!print_state(philo, philo->id + 1, GREEN, FORK))
		return (d_forks(philo, 1), 0);
	pthread_mutex_lock(&philo->data->ph_mutex[philo->r_fork]);
	if (!print_state(philo, philo->id + 1, GREEN, FORK))
		return (d_forks(philo, 2), 0);
	if (!print_state(philo, philo->id + 1, GREEN, EAT))
		return (d_forks(philo, 2), 0);
	pthread_mutex_lock(&philo->data->tm);
	philo->t_die = get_time();
	pthread_mutex_unlock(&philo->data->tm);
	time_sim(philo->data->t_eat);
	d_forks(philo, 2);
	pthread_mutex_lock(&philo->data->mem_shared);
	philo->num_eaten++;
	pthread_mutex_unlock(&philo->data->mem_shared);
	return (1);
}

int	print_state(t_philo *philo, int id, char *color, char *status)
{
	long long	now;

	now = time_diff(philo->data->time);
	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->mem_shared);
	if (philo->data->philo_died)
	{
		pthread_mutex_unlock(&philo->data->mem_shared);
		pthread_mutex_unlock(&philo->data->print);
		return (0);
	}
	else
		printf("%s%-10lld %-3d %-30s%s\n", color, now, id, status, RESET);
	pthread_mutex_unlock(&philo->data->mem_shared);
	pthread_mutex_unlock(&philo->data->print);
	return (1);
}

void	time_sim(long long time)
{
	usleep(time * 1000);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	time_diff(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}
