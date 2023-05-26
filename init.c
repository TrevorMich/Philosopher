/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:44:01 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/26 12:25:42 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **argv, int argc)
{
	int	i;

	data->philo_died = 0;
	data->num_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_eat = ft_atoi(argv[5]);
	else
		data->num_eat = -1;
	if (!data->num_philo || !data->t_die || !data->t_eat || !data->t_sleep
		|| (argc == 6 && !data->num_eat))
		return (printf("Error: some arguments are zero or out of bound\n"), 0);
	data->ph_mutex = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->ph_mutex)
		return (printf("Error: Memory allocation failed\n"), 0);
	i = 0;
	while (i < data->num_philo)
		if (pthread_mutex_init(data->ph_mutex + i++, NULL))
			return (printf("Error: Initialisation of mutex failed.\n"), 0);
	if (pthread_mutex_init(&data->print, NULL))
		return (printf("Error: Initialisation of mutex failed.\n"), 0);
	return (1);
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		philo[i].id = i;
		philo[i].l_fork = i;
		philo[i].r_fork = (i + 1) % data->num_philo;
		philo[i].num_eaten = 0;
		philo[i].t_die = 0;
		philo[i].data = data;
		i++;
	}
	philo[i].t_die = 0;
	philo[i].num_eaten = 0;
	philo[i].data = data;
}

int	ft_isdigit(int digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	return (0);
}
