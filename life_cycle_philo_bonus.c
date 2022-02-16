/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_philo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:35:27 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/15 17:37:10 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

void	*life_cycle(void *obj)
{
	t_philos	*philos;

	philos = (t_philos *)obj;
	pthread_create(&philos->dead, NULL, check_dead, (void *)philos);
	if (philos->number % 2 == 0)
		ft_usleep(philos->env->time_to_eat / 10, philos->env->start_time);
	while (!(philos->env->dead))
	{
		take_forks(philos);
		eat(philos);
		if (philos->eaten_meals >= philos->env->nb_should_eat)
			break ;
		p_sleep(philos);
		think(philos);
	}
	pthread_join(philos->dead, NULL);
	exit(EXIT_ALIVE);
	return (obj);
}
