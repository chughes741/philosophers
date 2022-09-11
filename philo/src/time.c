/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:37:52 by chughes           #+#    #+#             */
/*   Updated: 2022/09/11 12:48:10 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Returns current time since Epoch in ms
time_t	get_time(void)
{
	struct timeval	t_now;
	time_t			t_ms;

	if (gettimeofday(&t_now, NULL) == -1)
		exit_error("Error getting time of day");
	t_ms = (t_now.tv_sec / 1000) + (t_now.tv_sec * 1000);
	return (t_ms);
}
