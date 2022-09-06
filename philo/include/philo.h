/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/09/06 14:59:37 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h> //? memset
# include <stdio.h> //? printf
# include <stdlib.h> //? malloc, free
# include <unistd.h> //? usleep
# include <sys/time.h> //? gettimeofday
# include <pthread.h> //? pthread_create, pthread_detach, pthread_join, 
//? pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

typedef struct s_philo {
	pthread_t	id;
	int	state;
}		t_philo;

typedef struct s_data {
	t_philo	*philos;
}			t_data;

// Data functions
t_data	*get_data(void);
void	del_data(void);

#endif