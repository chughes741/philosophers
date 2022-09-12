/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:19:30 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 12:31:52 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_sleep(int id)
{
	t_data	*data;

	data = get_data();
	print_action(P_SLEEP, id);
	usleep(data->time_sleep * 100);
	return ;
}
