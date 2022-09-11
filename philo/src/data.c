/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:37:14 by chughes           #+#    #+#             */
/*   Updated: 2022/09/11 12:30:30 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Initialize data struct with inputs
void	init_data(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	data->n_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->n_eat = ft_atoi(argv[5]);
	else
		data->n_eat = -1;
	data->philos = ft_calloc(data->n_philos + 1, sizeof(t_philo *));
	init_forks();
	return ;
}

// Singleton constructor
t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (data == NULL)
		data = ft_calloc(1, sizeof(t_data));
	return (data);
}

// Data struct deconstructor
void	del_data(void)
{
	t_data	*data;

	data = get_data();
	destroy_forks();
	if (data)
		free(data);
	return ;
}
