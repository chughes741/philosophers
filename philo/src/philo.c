/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/09/10 14:18:07 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*init_thread(void *varg)
{
    return (NULL);
}

int	main(int argc, char *argv[])
{
    if (argc != 5 || argc != 6)
        exit_error("Wrong number of arguments");
    init_data(argc, argv);
    if (!get_data())
        exit_error("Error initializing data");
    init_philos();
    del_data();
    exit(0);
}
