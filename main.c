/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:32:29 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/14 19:17:02 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_filos(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nb_of_philos)
	{
		env->philos[i].env = env;
		env->philos[i].right_to_write = &env->right_to_write;
		env->philos[i].eaten_meals = 0;
		env->philos[i].time_to_die = env->time_to_die;
		if (i == env->nb_of_philos - 1)
		{
			env->philos[i].first_fork = &env->forks[0];
			env->philos[i].second_fork = &env->forks[i];
		}
		else
		{
			env->philos[i].first_fork = &env->forks[i];
			env->philos[i].second_fork = &env->forks[i + 1];
		}
	}
}

void	run_programm(t_env *env)
{
	pthread_mutex_init(&env->right_to_write, NULL);
	make_filos(env);
	creating_threads(env);
}

void	end_programm(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_of_philos)
		if (env->forks)
			pthread_mutex_destroy(&(env->forks[i++]));
	if (env->forks)
		free(env->forks);
	if (env->philos)
		free(env->philos);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (!check_param(argc, argv))
		return (0);
	if (!init_env(&env, argv, argc))
		return (0);
	run_programm(&env);
	end_programm(&env);
	return (1);
}
