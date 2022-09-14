/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:37:52 by chughes           #+#    #+#             */
/*   Updated: 2022/09/14 12:56:48 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Sets start time of simulation
void	start_time(void)
{
	t_data	*data;

	data = get_data();
	gettimeofday(&data->time, NULL);
	return ;
}

// Returns current time since Epoch in ms
time_t	get_time(void)
{
	t_data			*data;
	struct timeval	t_now;

	data = get_data();
	gettimeofday(&t_now, NULL);
	return (((t_now.tv_sec - data->time.tv_sec) * 1000)
		+ ((t_now.tv_usec - data->time.tv_usec) / 1000));
}
