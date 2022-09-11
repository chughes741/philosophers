/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:06:54 by chughes           #+#    #+#             */
/*   Updated: 2022/09/11 13:55:03 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Thread runtime for philos
void	*live(void *ptr)
{
	while (ptr) //TODO lifetime loop
	{
		return (NULL);
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
		if (pthread_create(&data->philos[i]->id, NULL, &live, NULL))
			exit_error("Error creating threads");
	}
	i = 0;
	while (++i <= data->n_philos)
	{
		if (pthread_join(data->philos[i]->id, NULL) != 0)
			exit_error("Error reabsorbing my spawn");
	}
	return ;
}
