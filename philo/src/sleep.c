/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:19:30 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 12:23:34 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep(int id)
{
	t_data	*data;
	time_t	time;

	data = get_data();
	time = get_time() - data->start_time;
	print_action(P_SLEEP, time , id);
	usleep(data->time_sleep * 1000);
	return ;
}
