/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:18:31 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/13 12:53:58 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *p)
{
	printf("%ld %d %s\n", (get_time() - p->lst->t_start), p->id, TAKE_FORK);
	usleep(p->lst->time_die * 1000);
	printf("%d %d %s\n", p->lst->time_die, p->id, DEAD);
}

void	eating(t_philo *p)
{
	long int	time;

	if (check_if_alive(p) == 1)
		return ;
	pthread_mutex_lock(p->l_fork);
	print_info(p, TAKE_FORK);
	pthread_mutex_lock(p->r_fork);
	print_info(p, TAKE_FORK);
	time = print_info(p, EATING);
	pthread_mutex_lock(&p->lst->m_meal);
	p->last_meal = time;
	pthread_mutex_unlock(&p->lst->m_meal);
	usleep(p->lst->time_eat * 1000);
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
	if (p->meal > 0)
		p->meal--;
}

void	sleeping_thinking(t_philo *p)
{
	print_info(p, SLEEPING);
	usleep(p->lst->time_sleep * 1000);
	print_info(p, THINKING);
	usleep(100);
}

long int	print_info(t_philo *p, char *str)
{
	if (check_if_alive(p) == 0)
	{
		pthread_mutex_lock(&p->lst->m_printf);
		printf("%ld %d %s\n", (get_time() - p->lst->t_start), p->id, str);
		pthread_mutex_unlock(&p->lst->m_printf);
	}
	return (get_time());
}
