/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:32:46 by mjodge            #+#    #+#             */
/*   Updated: 2021/12/14 18:40:59 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	check_chars(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (argv[i][++j] != '+' && argv[i][j] != '-' && !ft_isdigit(argv[i][j]))
			return (0);
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (0);
	}
	return (1);
}

int	check_param(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (!check_chars(argv))
	{
		printf("Wrong input");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 \
	|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
	{
		printf("Wrong input");
		return (0);
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
		{
			printf("Wrong input");
			return (0);
		}
	}
	return (1);
}
