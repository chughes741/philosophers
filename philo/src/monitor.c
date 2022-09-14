/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:30 by chughes           #+#    #+#             */
/*   Updated: 2022/09/14 12:55:59 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Monitors run state of philos
void	monitor_philos(void)
{
	t_data	*data;

	data = get_data();
	data->run = true;
	while (data->run == true)
	{
		check_death();
		usleep(10);
	}
	return ;
}

// Checks if any philos have died
void	check_death(void)
{
	t_data	*data;
	time_t	curr_time;
	int		i;

	data = get_data();
	curr_time = get_time();
	i = 0;
	while (++i <= data->n_philos)
	{
		if (((curr_time - data->philos[i].last_ate) >= data->time_die)
			&& (data->philos[i].n_eaten != data->n_eat))
		{
			print_action(P_DEAD, i);
			data->run = false;
		}
	}
	i = 0;
	while (++i <= data->n_philos)
	{
		if (data->philos[i].n_eaten != data->n_eat)
			break ;
		else if (data->philos[i].n_eaten == data->n_eat && i == data->n_philos)
			data->run = false;
	}
	return ;
}
