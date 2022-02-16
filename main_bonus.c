/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:29:28 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/15 17:51:22 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

void	end_programm(t_env *env)
{
	int	i;
	int	status;

	i = -1;
	while (++i < env->nb_philos)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == EXIT_DEAD)
		{
			i = -1;
			while (++i < env->nb_philos)
				kill(env->philos[i].pid, SIGTERM);
			break ;
		}
	}
	sem_close(env->print);
	sem_close(env->check);
	sem_close(env->forks);
	sem_unlink("/print");
	sem_unlink("/check");
	sem_unlink("/forks");
	free(env->philos);
}

int	run_programm(t_env *env)
{
	int	i;

	i = -1;
	env->start_time = get_time();
	while (++i < env->nb_philos)
	{
		env->philos[i].time_to_die = env->start_time;
		env->philos[i].pid = fork();
		if (env->philos[i].pid == -1)
			exit(EXIT_FAILURE);
		if (env->philos[i].pid == 0)
			life_cycle((void *)&env->philos[i]);
	}
	return (1);
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
