/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:36:55 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/13 12:13:54 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	argc = argc - 1;
	while (i <= argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("All arguments must be numbers\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_ints(int argc, char **argv)
{
	int	i;

	i = 0;
	argc = argc - 1;
	while (i <= argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX)
		{
			printf("Numbers can't be bigger than MAX\n");
			return (1);
		}
		if (ft_atoi(argv[i]) < 0)
		{
			printf("Arguments can't be inferior at 0.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check(int argc, char **argv)
{
	if (check_ints(argc, argv) == 1 || check_digits(argc, argv) == 1)
		return (1);
	return (0);
}
