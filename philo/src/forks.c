/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:31:38 by chughes           #+#    #+#             */
/*   Updated: 2022/09/11 10:29:34 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_forks(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	data->forks = ft_calloc(data->n_philos + 1, sizeof(pthread_mutex_t *));
	i = -1;
	while (++i < data->n_philos)
	{
		if (pthread_mutex_init(data->forks[i], NULL))
			exit_error("Error making forks");
	}
	return ;
}

void	destroy_forks(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = -1;
	while (++i < data->n_philos)
		pthread_mutex_destroy(data->forks[i]);
	free(data->forks);
	return ;
}
