/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:19:04 by chughes           #+#    #+#             */
/*   Updated: 2022/09/16 15:17:06 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Takes forks and eats with them
void	philo_eat(int id)
{
	t_data	*data;

	data = get_data();
	if (id == data->n_philos)
		pthread_mutex_lock(&data->forks[1]);
	else
		pthread_mutex_lock(&data->forks[id + 1]);
	print_action(P_FORK, id);
	while (data->n_philos == 1 && data->run)
		usleep(100);
	pthread_mutex_lock(&data->forks[id]);
	print_action(P_FORK, id);
	data->philos[id].last_ate = get_time();
	if (data->run == true)
		print_action(P_EAT, id);
	smart_sleep(data->time_eat);
	data->philos[id].n_eaten += 1;
	if (id == data->n_philos)
		pthread_mutex_unlock(&data->forks[1]);
	else
		pthread_mutex_unlock(&data->forks[id + 1]);
	pthread_mutex_unlock(&data->forks[id]);
	return ;
}
