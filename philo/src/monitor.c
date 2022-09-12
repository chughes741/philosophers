/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:13:30 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 16:23:35 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	monitor(void)
{
	while (0 == 0)
	{
		printf("Monitoring\n");
		check_death();
		usleep(10);
	}
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
		if ((curr_time - data->philos[i].last_ate) < data->time_die)
		{
			print_action(P_DEAD, i);
			data->philos[i].alive = false;
			exit_error("");
		}
	}
	return ;	
}
