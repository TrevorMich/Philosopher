/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:55:38 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/26 12:11:32 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	help2_routine1(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->data->mem_shared);
		if ((philo[i].data->num_eat > philo[i].num_eaten)
			&& !philo[i].data->philo_died)
		{
			pthread_mutex_unlock(&philo->data->mem_shared);
			if (its_dead(philo, &i))
				break ;
		}
		else
		{
			pthread_mutex_unlock(&philo->data->mem_shared);
			break ;
		}
	}
}

void	help2_routine2(t_philo *philo)
{
	int		i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->data->mem_shared);
		if (!philo[i].data->philo_died)
		{
			pthread_mutex_unlock(&philo->data->mem_shared);
			if (its_dead(philo, &i))
				break ;
		}
		else
		{
			pthread_mutex_unlock(&philo->data->mem_shared);
			break ;
		}
	}
}

void	help_routine2(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->mem_shared);
		if (!philo->data->philo_died)
		{
			pthread_mutex_unlock(&philo->data->mem_shared);
			if (!simulation(philo))
				break ;
		}
		else
		{
			pthread_mutex_unlock(&philo->data->mem_shared);
			break ;
		}
	}
}

void	help_routine1(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->mem_shared);
		if ((philo->data->num_eat > philo->num_eaten)
			&& !philo->data->philo_died)
		{
			pthread_mutex_unlock(&philo->data->mem_shared);
			simulation(philo);
		}
		else
		{
			pthread_mutex_unlock(&philo->data->mem_shared);
			break ;
		}
	}
}
