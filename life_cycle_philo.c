/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:32:41 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/14 21:42:00 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philos *philos)
{
	pthread_mutex_lock(philos->first_fork);
	pthread_mutex_lock(philos->right_to_write);
	if (!philos->env->stop)
		printf("%ld\tPhilosopher number %d taken first fork\n", \
		get_current_time(philos->env->start_time), philos->number);
	pthread_mutex_unlock(&philos->env->right_to_write);
	pthread_mutex_lock(philos->second_fork);
	pthread_mutex_lock(philos->right_to_write);
	if (!philos->env->stop)
		printf("%ld\tPhilosopher number %d taken second fork\n", \
		get_current_time(philos->env->start_time), philos->number);
	pthread_mutex_unlock(&philos->env->right_to_write);
}

void	eat(t_philos *philos)
{
	pthread_mutex_lock(philos->right_to_write);
	if (!philos->env->stop)
		printf("%ld\tPhilosopher number %d is eating\n", \
		get_current_time(philos->env->start_time), philos->number);
	pthread_mutex_unlock(&philos->env->right_to_write);
	ft_usleep(philos->env->time_to_eat, philos->env->start_time);
	philos->time_to_die = get_current_time(philos->env->start_time) \
	+ philos->env->time_to_die;
	philos->eaten_meals++;
	pthread_mutex_unlock(philos->first_fork);
	pthread_mutex_unlock(philos->second_fork);
}

void	p_sleep(t_philos *philos)
{
	pthread_mutex_lock(philos->right_to_write);
	if (!philos->env->stop)
		printf("%ld\tPhilosopher number %d is sleeping\n", \
		get_current_time(philos->env->start_time), philos->number);
	pthread_mutex_unlock(&philos->env->right_to_write);
	ft_usleep(philos->env->time_to_sleep, philos->env->start_time);
}

void	think(t_philos *philos)
{
	pthread_mutex_lock(philos->right_to_write);
	if (!philos->env->stop)
		printf("%ld\tPhilosopher number %d is thinking\n", \
		get_current_time(philos->env->start_time), philos->number);
	pthread_mutex_unlock(&philos->env->right_to_write);
}

void	*life_cycle(void *obj)
{
	t_philos	*philos;

	philos = (t_philos *)obj;
	philos->time_to_die = get_current_time(philos->env->start_time) \
	+ philos->env->time_to_die;
	if (philos->number % 2 == 0)
		ft_usleep(philos->env->time_to_eat, philos->env->start_time);
	while (!(philos->env->stop))
	{
		if (!philos->env->stop)
			take_forks(philos);
		if (!philos->env->stop)
			eat(philos);
		if (!philos->env->stop)
			p_sleep(philos);
		if (!philos->env->stop)
			think(philos);
	}
	return (obj);
}
