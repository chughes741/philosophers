/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/09/10 13:54:25 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*init_thread(void *varg)
{
    sleep(1);
    printf("Printing from a thread\n");
	printf("%p\n", varg);
    return (NULL);
}

int	main(int argc, char *argv[])
{
	t_data  *data;

    if (argc != 5 || argc != 6)
        exit(1);
    data = get_data();
    init_data(argc, argv);
    data->philos = malloc(sizeof(t_philo *));

    printf("Before Thread\n");
    pthread_create(&data->philos->id, NULL, init_thread, NULL);
    pthread_join(data->philos->id, NULL);
    printf("After Thread\n");
    exit(0);
}
