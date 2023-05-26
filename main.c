/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:23:48 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/26 12:43:48 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (checks(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("Failed to allocate memory\n"), 2);
	if (!init_data(data, argv, argc))
		return (3);
	philo = malloc(sizeof(t_philo) * (data->num_philo + 1));
	if (!philo)
		return (printf("Error: Allocation of memory failed\n"), 4);
	init_philo(philo, data);
	if (data->num_philo == 1)
	{
		one_philo(data, philo);
		return (0);
	}
	if (!create_thread(philo))
		return (free_all(data, philo), 5);
	free_all(data, philo);
	return (0);
}
