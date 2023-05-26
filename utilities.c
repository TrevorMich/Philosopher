/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:22:53 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/26 12:07:47 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	d_forks(t_philo *philo, int flag)
{
	pthread_mutex_unlock(&(philo->data->ph_mutex[philo->l_fork]));
	if (flag == 2)
		pthread_mutex_unlock(&(philo->data->ph_mutex[philo->r_fork]));
}

int	its_dead(t_philo *philo, int *i)
{
	int	time;

	if (*i == philo[*i].data->num_philo)
	{
		*i = 0;
		usleep(200);
	}
	pthread_mutex_lock(&philo->data->tm);
	time = time_diff(philo[*i].t_die);
	if (time > philo[*i].data->t_die)
	{
		pthread_mutex_unlock(&philo->data->tm);
		print_state(&philo[*i], philo[*i].id + 1, RED, DIED);
		pthread_mutex_lock(&philo->data->mem_shared);
		philo[*i].data->philo_died = 1;
		pthread_mutex_unlock(&philo->data->mem_shared);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->tm);
	*i = *i + 1;
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	if (!print_state(philo, philo->id + 1, CYAN, SLEEP))
		return (0);
	time_sim(philo->data->t_sleep);
	return (1);
}

int	philo_think(t_philo *philo)
{
	if (!print_state(philo, philo->id + 1, YELLOW, THINK))
		return (0);
	return (1);
}

void	one_philo(t_data *data, t_philo *philo)
{
	data->time = get_time();
	print_state(philo, 1, GREEN, FORK);
	time_sim(data->t_die);
	print_state(philo, 1, RED, DIED);
	free_all(data, philo);
}
