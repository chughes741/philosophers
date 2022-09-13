/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:30 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 20:49:30 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
		if ((curr_time - data->philos[i].last_ate) >= data->time_die)
		{
			print_action(P_DEAD, i);
			data->run = false;
		}
	}
	return ;	
}
