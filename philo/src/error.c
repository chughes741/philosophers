/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:55:14 by chughes           #+#    #+#             */
/*   Updated: 2022/09/10 13:57:04 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Exits program and prints 'message' to STDOUT
void	exit_error(char *message)
{
	del_data();
	printf("%s\n", message);
	exit(1);
}
