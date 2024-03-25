/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:23:58 by xortega           #+#    #+#             */
/*   Updated: 2024/03/21 11:29:28 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_parameters
{
	int					n_of_p;
	int					t_to_d;
	int					t_to_e;
	int					t_to_s;
	int					must_e;
	bool				end_sim;
	long				time_s;
	pthread_mutex_t		sim_mutex;
	pthread_mutex_t		print_mutex;
}				t_parameters;

typedef struct s_philo
{
	pthread_t			th;
	int					id;
	int					t_eaten;
	long				last_eat;
	pthread_mutex_t		forke;
	bool				full;
	struct s_philo		*next;
	struct s_parameters	*args;
}				t_philo;

//PARSE
void	parse(int argc, char const *argv[], t_parameters **args);
int		ft_atoi(const char *str);
int		ft_is_alpha(const char **str);
//SIMULATION
void	sim(t_philo **philos);
void	*watcher(void *philo);
void	*rutine(void *philo);
void	check_full(t_philo *philo, int n_of_p);
//TIME
long	ft_time(void);
void	ft_usleep(unsigned int ms);
//ACTIONS
void	print_action(t_philo *philo, char *action);
void	eating(t_philo *philo);
void	dying(t_philo *philo);

#endif