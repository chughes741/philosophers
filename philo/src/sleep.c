/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:19:30 by chughes           #+#    #+#             */
/*   Updated: 2022/09/11 15:44:21 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep(int id)
{
	t_data	*data;
	time_t	time;

	data = get_data();
	time = get_time() - data->start_time;
	printf("%lims %i is sleeping\n", time , id);
	usleep(data->time_sleep * 1000);
	return ;
}
