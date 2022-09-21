/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/09/21 16:48:05 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		exit_error("Wrong number of arguments");
	init_data(argc, argv);
	data = get_data();
	if (data->n_philos)
	{
		init_forks();
		init_philos();
		monitor_philos();
		destroy_philos();
	}
	del_data();
	exit(0);
}
