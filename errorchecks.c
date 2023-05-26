/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:25:27 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/15 20:44:37 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (nbr > 2147483647)
		return (0);
	return (nbr);
}

int	checks(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("Check number of arguments inputted!\n"), 1);
	if (!check_arg(argv))
		return (printf("Error: Arguments must be integers!\n"), 2);
	return (0);
}
