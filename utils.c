/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:23:47 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/13 12:08:58 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atoi(char *str)
{
	int			i;
	int			j;
	long int	value;

	i = 0;
	j = 0;
	value = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - 48);
		i++;
	}
	if (j == 1)
		return (value * -1);
	else
		return (value);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long int	get_time(void)
{
	long int		time_now;
	struct timeval	time;

	time_now = 0;
	gettimeofday(&time, NULL);
	time_now = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_now);
}
