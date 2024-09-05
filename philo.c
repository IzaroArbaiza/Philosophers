/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:48:30 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/13 12:10:10 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_list	lst;

	if (argc == 5 || argc == 6)
	{
		if (get_args(argc, argv, &lst) == 1)
			return (1);
	}
	else
	{
		printf("Invalid amount of arguments\n");
		return (1);
	}
	init_threads(&lst);
	if (lst.num_philo > 1 && lst.num_meals == 0)
		check_death(&lst);
	else if (lst.num_philo > 1 && lst.num_meals > 0)
		check_death_meals(&lst);
	join_threads(&lst);
	ft_free(&lst);
	return (0);
}
