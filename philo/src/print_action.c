/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:19:06 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 16:11:14 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*print_action(int action, int id)
{
	t_data	*data;

	data = get_data();
	pthread_mutex_lock(&data->action);
	if (action == P_EAT)
		printf("%10lims %i is eating\n", get_time(), id);
	else if (action == P_THINK)
		printf("%10lims %i is thinking\n", get_time(), id);
	else if (action == P_SLEEP)
		printf("%10lims %i is sleeping\n", get_time(), id);
	else if (action == P_DONE)
		printf("%10lims %i has finished eating\n", get_time(), id);
	else if (action == P_DEAD)
		printf("%10lims %i has died\n", get_time(), id);
	pthread_mutex_unlock(&data->action);
	return (NULL);
}
