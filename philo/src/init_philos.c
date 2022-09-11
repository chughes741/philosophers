/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:06:54 by chughes           #+#    #+#             */
/*   Updated: 2022/09/10 20:29:45 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*live(void *ptr)
{
	(void)ptr;
	return (NULL);
}

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
