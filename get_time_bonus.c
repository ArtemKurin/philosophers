/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:33:11 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/14 22:59:25 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return (start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
}

long	get_current_time(long time)
{
	struct timeval	*start_time;
	time_t			current;

	start_time = malloc(sizeof(struct timeval) * 1);
	gettimeofday(start_time, NULL);
	current = start_time->tv_sec * 1000 + start_time->tv_usec / 1000;
	return (current - time);
}
// long	get_current_time(long time)
// {
// 	(void)time;
// 	return(2);
// }