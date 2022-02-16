/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:54:14 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/11 22:44:13 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return (start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
}

long	get_current_time(long time)
{
	struct timeval	start_time;
	long			current;

	gettimeofday(&start_time, NULL);
	current = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	return (current - time);
}
