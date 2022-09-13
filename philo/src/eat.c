/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:19:04 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 20:54:33 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(int id)
{
	t_data	*data;

	data = get_data();
	data->philos[id].last_ate = get_time();
	if (id == data->n_philos)
		pthread_mutex_lock(&data->forks[0]);
	else
		pthread_mutex_lock(&data->forks[id + 1]);
	pthread_mutex_lock(&data->forks[id]);
	if (data->run == true)
		print_action(P_EAT, id);
	usleep(1000 * data->time_eat);
	data->philos[id].n_eaten += 1;
	if (data->philos[id].n_eaten == data->n_eat)
	{
		print_action(P_DONE, id);
		data->run = false;
	}
	if (id == data->n_philos)
		pthread_mutex_unlock(&data->forks[0]);
	else
		pthread_mutex_unlock(&data->forks[id + 1]);
	pthread_mutex_unlock(&data->forks[id]);
	return ;
}
