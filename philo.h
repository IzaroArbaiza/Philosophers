/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:58:46 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/13 11:42:53 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define TAKE_FORK	"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define DEAD		"died"

typedef struct s_philo
{
	int				id;
	int				meal;
	long int		last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_list	*lst;
}	t_philo;

typedef struct s_list
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_meals;
	long int		t_start;
	int				dead;
	t_philo			*p;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_meal;
	pthread_mutex_t	m_printf;
	pthread_mutex_t	m_death;
}	t_list;

/* Check_args */
int			check_digits(int argc, char **argv);
int			check_ints(int argc, char **argv);
int			check(int argc, char **argv);

/* Get_agrs */
void		get_meals(t_list *lst, int nb);
int			get_args(int argc, char **argv, t_list *lst);

/* Initialize */
int			init_mutex_forks(t_list *lst, int num);
int			init_mutex(t_list *lst);
int			init_philo(t_list *lst);
int			init_threads(t_list *lst);
int			join_threads(t_list *lst);

/* Actions */
void		one_philo(t_philo *p);
void		eating(t_philo *p);
void		sleeping_thinking(t_philo *p);
long int	print_info(t_philo *p, char *str);

/* Routine */
void		init_meals(t_philo *p);
long int	last_meal(t_list *lst, long int actual_time, int i);
int			finish_eating(t_list *lst);
void		meals(t_philo *p);
void		*routine(void *arg);

/* Check_death */
void		philo_dead(t_list *lst, long int actual_time, int i);
int			check_if_alive(t_philo *p);
void		check_death(t_list *lst);
void		check_death_meals(t_list *lst);

/* Utils */
long int	ft_atoi(char *str);
int			ft_isdigit(int c);
int			ft_strlen(char	*str);
long int	get_time(void);

/* Free */
void		ft_free(t_list *lst);

#endif