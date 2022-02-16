/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:47:43 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/15 21:49:54 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead(t_env *env, int i)
{
	if (env->philos[i].time_to_die <= get_current_time(env->start_time))
	{
		pthread_mutex_lock(&env->right_to_write);
		// env->stop = 1;
		printf("%ld\t%d philosopher is dead\n", \
		get_current_time(env->start_time), i + 1);
		pthread_mutex_destroy(&env->right_to_write);
		return (1);
	}
	return (0);
}

void	observer(t_env *env)
{
	int	i;
	int	num_of_philos_eaten_all;

	while (1)
	{
		i = 0;
		num_of_philos_eaten_all = 0;
		while (i < env->nb_of_philos)
		{
			if (env->philos[i].eaten_meals >= env->nb_should_eat)
				num_of_philos_eaten_all++;
			if (dead(env, i++))
				return ;
		}
		if (num_of_philos_eaten_all == env->nb_of_philos)
		{
			// env->stop = 1;
			pthread_mutex_lock(&env->right_to_write);
			pthread_mutex_destroy(&env->right_to_write);
			return ;
		}
		usleep(500);
	}
}

void	creating_threads(t_env *env)
{
	int			i;
	pthread_t	*philo_thread;

	philo_thread = malloc(env->nb_of_philos * sizeof(pthread_t));
	if (!philo_thread)
		return ;
	i = 0;
	env->start_time = get_time();
	while (i < env->nb_of_philos)
	{
		if (pthread_create(&philo_thread[i], NULL, \
		life_cycle, (void *)(env->philos + i)))
		{
			pthread_mutex_lock(&env->right_to_write);
			pthread_mutex_destroy(&env->right_to_write);
			free(philo_thread);
			printf("Couldn't create a thread for %d philosopher\n", i);
			return ;
		}
		pthread_detach(philo_thread[i]);
		i++;
	}
	observer(env);
	free(philo_thread);
}
