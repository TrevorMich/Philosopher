/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:13:17 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/26 13:03:22 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine2(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->data->num_eat > 0)
		help2_routine1(philo);
	else
		help2_routine2(philo);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->data->num_eat > 0)
		help_routine1(philo);
	else
		help_routine2(philo);
	return (NULL);
}

int	simulation(t_philo *philo)
{
	if (!philo_eat(philo))
		return (0);
	if (philo->num_eaten != philo->data->num_eat)
	{
		if (!philo_sleep(philo))
			return (0);
		if (!philo_think(philo))
			return (0);
	}
	return (1);
}

int	create_thread(t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&philo->data->mem_shared, NULL))
		return (printf("Initialisation of mutex failed\n"), 0);
	if (pthread_mutex_init(&philo->data->tm, NULL))
		return (printf("Initialisation of mutex failed\n"), 0);
	if (pthread_create(&philo[0].data->monitor, NULL, routine2, philo))
		return (printf("Error: Failed to create thread\n"), 0);
	usleep(2000);
	philo->data->time = get_time();
	while (i < philo->data->num_philo)
	{
		if (pthread_create(&philo[i].th, NULL, routine, &philo[i]))
			return (printf("Error: Failed to create threads\n"), 0);
		i++;
		usleep(2000);
	}
	i = -1;
	while (++i < philo->data->num_philo)
		if (pthread_join(philo[i].th, NULL))
			return (printf("Error: Failed in joining threads\n"), 0);
	if (pthread_join(philo->data->monitor, NULL))
		return (printf("Error: failed to join thread\n"), 0);
	return (1);
}

void	free_all(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_destroy(data->ph_mutex + i);
	pthread_mutex_destroy(&data->tm);
	pthread_mutex_destroy(&data->mem_shared);
	pthread_mutex_destroy(&data->print);
	free(data->ph_mutex);
	free(philo);
	free(data);
}
