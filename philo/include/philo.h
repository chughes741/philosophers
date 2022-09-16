/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:50:16 by chughes           #+#    #+#             */
/*   Updated: 2022/09/16 11:17:42 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define P_FORK		0
# define P_EAT		1
# define P_THINK	2
# define P_SLEEP	3
# define P_DEAD		4

typedef struct s_philo {
	pthread_t	id;
	time_t		last_ate;
	int			n_eaten;
}		t_philo;

typedef struct s_data {
	bool			run;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	action;
	struct timeval	time;
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

// pthread and mutex functions
void	init_philos(void);
void	init_forks(void);
void	monitor_philos(void);
void	destroy_philos(void);
void	destroy_forks(void);

// Action functions
void	*print_action(int action, int id);
void	philo_eat(int id);
void	philo_sleep(int id);
void	philo_think(int id);
void	smart_sleep(time_t slp);

// LibC and utility functions
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
time_t	get_time(void);
void	start_time(void);
void	check_death(void);

#endif