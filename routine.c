/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:12:25 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/13 11:40:29 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_meals(t_philo *p)
{
	pthread_mutex_lock(&p->lst->m_meal);
	p->last_meal = p->lst->t_start;
	pthread_mutex_unlock(&p->lst->m_meal);
	if (p->id % 2)
		usleep(30000);
}

long int	last_meal(t_list *lst, long int time, int i)
{
	long int	l_meal;

	pthread_mutex_lock(&lst->m_meal);
	l_meal = time - lst->p[i].last_meal;
	pthread_mutex_unlock(&lst->m_meal);
	return (l_meal);
}

int	finish_eating(t_list *lst)
{
	pthread_mutex_lock(&lst->m_meal);
	if (lst->num_meals == 0)
	{
		pthread_mutex_unlock(&lst->m_meal);
		return (1);
	}
	pthread_mutex_unlock(&lst->m_meal);
	return (0);
}

void	meals(t_philo *p)
{
	while (check_if_alive(p) == 0 && (p->meal > 0))
	{
		eating(p);
		if (p->meal >= 0)
			sleeping_thinking(p);
		pthread_mutex_lock(&p->lst->m_meal);
		p->lst->num_meals--;
		pthread_mutex_unlock(&p->lst->m_meal);
	}
}

void	*routine(void *args)
{
	t_philo	*p;

	p = (t_philo *)args;
	if (p->lst->num_philo == 1)
	{
		one_philo(p);
		return (0);
	}
	init_meals(p);
	if (p->meal == 0)
	{
		while (check_if_alive(p) == 0)
		{
			eating(p);
			sleeping_thinking(p);
		}
		return (0);
	}
	if (p->meal > 0)
	{
		meals(p);
		return (0);
	}
	return (0);
}
