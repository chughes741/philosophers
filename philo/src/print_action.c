/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:19:06 by chughes           #+#    #+#             */
/*   Updated: 2022/09/13 16:15:56 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Prints status message of philo
void	*print_action(int action, int id)
{
	t_data	*data;

	data = get_data();
	pthread_mutex_lock(&data->action);
	if (data->run == false)
		;
	else if (action == P_FORK)
		printf("%li %i has taken a fork\n", get_time(), id);
	else if (action == P_EAT)
		printf("%li %i is eating\n", get_time(), id);
	else if (action == P_THINK)
		printf("%li %i is thinking\n", get_time(), id);
	else if (action == P_SLEEP)
		printf("%li %i is sleeping\n", get_time(), id);
	else if (action == P_DEAD)
		printf("%li %i died\n", get_time(), id);
	pthread_mutex_unlock(&data->action);
	return (NULL);
}
