/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/09/06 15:00:03 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
	printf("%p\n", vargp);
    return NULL;
}

int	main()
{
	t_data  *data;

    data = get_data();
    data->philos = malloc(sizeof(t_philo *));
    printf("Before Thread\n");
    pthread_create(&data->philos->id, NULL, myThreadFun, NULL);
    pthread_join(data->philos->id, NULL);
    printf("After Thread\n");
    exit(0);
}
