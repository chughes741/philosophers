/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:37:14 by chughes           #+#    #+#             */
/*   Updated: 2022/09/06 15:09:18 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Initialize data struct with inputs
void	init_data(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	data->n_philos = atoi(argv[1]);
	data->time_die = atoi(argv[2]);
	data->time_eat = atoi(argv[3]);
	data->time_sleep = atoi(argv[4]);
	if (argc == 6)
		data->n_eat = atoi(argv[5]);
	return ;
}

// Singleton constructor
t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (data == NULL)
	{
		data = malloc(1 * sizeof(t_data));
		memset(data, 0, sizeof(t_data));
	}
	return (data);
}

// Data struct deconstructor
void	del_data(void)
{
	t_data	*data;

	data = get_data();
	if (data)
	{
		free(data);
	}
	return ;
}
