/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/09/12 12:24:24 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>	//? memset
# include <stdio.h>		//? printf
# include <stdlib.h>	//? malloc, free
# include <unistd.h>	//? usleep
# include <sys/time.h>	//? gettimeofday
# include <pthread.h>	//? pthread_create, pthread_detach, pthread_join, 
						//? pthread_mutex_init, pthread_mutex_destroy,
						//? pthread_mutex_lock, pthread_mutex_unlock
# include <stdbool.h>

# define P_EAT		1
# define P_THINK	2
# define P_SLEEP	3

typedef struct s_philo {
	pthread_t	id;
	bool		alive;
}		t_philo;

typedef struct s_data {
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	action;
	time_t			start_time;
	int				n_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_eat;
}					t_data;

// Data functions
void	init_data(int argc, char *argv[]);
t_data	*get_data(void);
void	del_data(void);

// Error handling
void	exit_error(char *message);

// pthread functions
void	init_philos(void);

// mutex functions
void	init_forks(void);
void	destroy_forks(void);

// Action functions
void	print_action(int action, time_t time, int id);
void	philo_eat(int id);
void	philo_sleep(int id);
void	philo_think(int id);

// LibC and utility functions
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
time_t	get_time(void);

#endif