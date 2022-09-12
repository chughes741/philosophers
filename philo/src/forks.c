/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:31:38 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 11:51:26 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Initializes fork mutexs
void	init_forks(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	data->forks = ft_calloc(data->n_philos + 1, sizeof(pthread_mutex_t));
	if (pthread_mutex_init(&data->change_state, NULL))
		exit_error("Error initializing mutex");
	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			exit_error("Error making forks");
	}
	return ;
}

// Destroys fork mutexs
void	destroy_forks(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	pthread_mutex_destroy(&data->change_state);
	i = -1;
	while (++i < data->n_philos)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
	return ;
}
