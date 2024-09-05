/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:53:11 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/08 13:09:42 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_list *lst)
{
	int	i;

	i = 0;
	free(lst->thread);
	free(lst->p);
	while (i < lst->num_philo)
	{
		pthread_mutex_destroy(&lst->fork[i]);
		i++;
	}
	free(lst->fork);
	pthread_mutex_destroy(&lst->m_meal);
	pthread_mutex_destroy(&lst->m_printf);
	pthread_mutex_destroy(&lst->m_death);
}
