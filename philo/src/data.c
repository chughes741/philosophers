/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/09/06 14:50:56 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
