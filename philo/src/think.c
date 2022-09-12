/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:19:58 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 12:23:27 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_think(int id)
{
	t_data	*data;
	time_t	time;

	data = get_data();
	time = get_time() - data->start_time;
	print_action(P_THINK, time , id);
	return ;
}
