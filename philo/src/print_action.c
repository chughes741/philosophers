/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:19:06 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 12:31:39 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_action(int action, int id)
{
	t_data	*data;
	time_t	time;

	data = get_data();
	time = get_time() - data->start_time;
	pthread_mutex_lock(&data->action);
	if (action == 1)
		printf("%lims %i is eating\n", time, id);
	else if (action == 2)
		printf("%lims %i is thinking\n", time, id);
	else if (action == 3)
		printf("%lims %i is sleeping\n", time, id);
	else
		printf("%lims %i has died\n", time, id);
	pthread_mutex_unlock(&data->action);
	return ;
}