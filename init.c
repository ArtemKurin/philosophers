/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:17:18 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/13 16:59:22 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_env *env)
{
	int	i;

	i = 0;
	env->forks = malloc(sizeof(pthread_mutex_t) * env->nb_of_philos);
	if (!env->forks)
		return (0);
	while (i < env->nb_of_philos)
		pthread_mutex_init(&(env->forks[i++]), NULL);
	return (1);
}

int	get_filos(t_env *env)
{
	int	i;

	i = -1;
	env->philos = malloc(sizeof(t_philos) * env->nb_of_philos);
	if (!env->philos)
		return (0);
	while (++i < env->nb_of_philos)
		env->philos[i].number = i + 1;
	return (1);
}

int	init_env(t_env *env, char **argv, int argc)
{
	env->nb_of_philos = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->stop = 0;
	if (argc == 6)
		env->nb_should_eat = ft_atoi(argv[5]);
	else
		env->nb_should_eat = INT_MAX;
	if (!get_filos(env))
	{
		printf("Error");
		return (0);
	}
	if (!init_forks(env))
	{
		printf("Error");
		return (0);
	}
	return (1);
}
