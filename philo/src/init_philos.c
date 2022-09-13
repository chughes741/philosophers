/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:06:54 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 20:43:02 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Thread runtime for philos
void	*live(void *ptr)
{
	t_data	*data;
	int		philo_id;

	philo_id = *(int *)ptr;
	data = get_data();
	pthread_mutex_lock(&data->action);
	pthread_mutex_unlock(&data->action);
	data->philos[philo_id].last_ate = get_time();
	if (philo_id % 2 == 0)
		usleep(100);
	while (data->run == true)
	{
		philo_eat(philo_id);
		philo_sleep(philo_id);
		philo_think(philo_id);
		if (data->philos[philo_id].n_eaten == data->n_eat)
			return (print_action(P_DONE, philo_id));
	}
	return (NULL);
}

// Creates and destroys threads
void	init_philos(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = 0;
	pthread_mutex_lock(&data->action);
	while (++i <= data->n_philos)
	{
		if (pthread_create(&data->philos[i].id, NULL, &live, &i))
			exit_error("Error creating threads");
		usleep(100);
	}
	start_time();
	pthread_mutex_unlock(&data->action);
	return ;
}

void	destroy_philos(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = 0;
	while (++i <= data->n_philos)
		pthread_join(data->philos[i].id, NULL);
	return ;
}
