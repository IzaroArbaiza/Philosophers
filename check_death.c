/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:48:30 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/14 10:01:40 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_list *lst, long int time, int i)
{
	pthread_mutex_lock(&lst->m_death);
	lst->dead = 1;
	pthread_mutex_unlock(&lst->m_death);
	printf("%ld %d %s\n", (time - lst->t_start), lst->p[i].id, DEAD);
}

int	check_if_alive(t_philo *p)
{
	pthread_mutex_lock(&p->lst->m_death);
	if (p->lst->dead == 1)
	{
		pthread_mutex_unlock(&p->lst->m_death);
		return (1);
	}
	pthread_mutex_unlock(&p->lst->m_death);
	return (0);
}

void	check_death(t_list *lst)
{
	int			i;
	long int	time;
	long int	meal_time;

	usleep(30000);
	i = 0;
	while (1)
	{
		time = get_time();
		meal_time = last_meal(lst, time, i);
		if (meal_time > lst->time_die)
		{
			philo_dead(lst, time, i);
			return ;
		}
		i++;
		if (i == (lst->num_philo - 1))
			i = 0;
		usleep(10);
	}
}

void	check_death_meals(t_list *lst)
{
	int			i;
	long int	time;
	long int	meal_time;

	usleep(30000);
	i = 0;
	while (1 && finish_eating(lst) == 1)
	{
		time = get_time();
		meal_time = last_meal(lst, time, i);
		if (meal_time > lst->time_die && finish_eating(lst) == 1)
		{
			philo_dead(lst, time, i);
			return ;
		}
		i++;
		if (i == (lst->num_philo - 1))
			i = 0;
		usleep(10);
	}
	return ;
}
