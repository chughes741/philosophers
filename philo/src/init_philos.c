/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:06:54 by chughes           #+#    #+#             */
/*   Updated: 2022/09/11 15:31:19 by chughes          ###   ########.fr       */
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
	data->philos[philo_id].alive = true;
	while (data->philos[philo_id].alive)
	{
		philo_eat(philo_id);
		philo_sleep(philo_id);
		philo_think(philo_id);
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
	while (++i <= data->n_philos)
	{
		if (pthread_create(&data->philos[i].id, NULL, &live, &i))
			exit_error("Error creating threads");
	}
	i = 0;
	while (++i <= data->n_philos)
	{
		if (pthread_join(data->philos[i].id, NULL) != 0)
			exit_error("Error reabsorbing my spawn");
	}
	return ;
}
