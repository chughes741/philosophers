/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:19:58 by chughes           #+#    #+#             */
/*   Updated: 2022/09/11 15:37:05 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_think(int id)
{
	t_data	*data;
	time_t	time;

	data = get_data();
	time = get_time() - data->start_time;
	printf("%lims %i is thinking\n", time , id);
	return ;
}
