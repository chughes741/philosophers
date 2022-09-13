/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:19:30 by chughes           #+#    #+#             */
/*   Updated: 2022/09/13 16:19:41 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep(int id)
{
	t_data	*data;

	data = get_data();
	smart_sleep(data->time_sleep);	
	print_action(P_SLEEP, id);
	return ;
}

void	smart_sleep(time_t slp)
{
	t_data	*data;
	time_t	now;

	data = get_data();
	now = get_time();
	while (data->run)
	{
		if (get_time() - now >= slp)
			break ;
		usleep(50);
	}
}
