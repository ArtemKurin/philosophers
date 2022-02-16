/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:23:08 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/14 18:23:09 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <limits.h>

typedef struct s_env	t_env;

typedef struct s_philos
{
	int				eaten_meals;
	t_env			*env;
	int				number;
	time_t			time_to_die;
	pthread_mutex_t	*right_to_write;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
}				t_philos;

typedef struct s_env
{
	int				nb_should_eat;
	int				nb_of_philos;
	int				stop;
	t_philos		*philos;
	long			start_time;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	right_to_write;
}				t_env;

void	run_programm(t_env *env);
void	end_programm(t_env *env);
int		ft_atoi(char *str);
int		check_param(int argc, char **argv);
void	creating_threads(t_env *env);
long	get_time(void);
long	get_current_time(long time);
void	*life_cycle(void *obj);
int		init_env(t_env *env, char **argv, int argc);
void	ft_usleep(time_t milisec, long start_time);

#endif