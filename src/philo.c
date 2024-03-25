/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:16:18 by xortega           #+#    #+#             */
/*   Updated: 2024/03/21 11:22:44 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo **philos, int n_of_p)
{
	t_philo	*current;
	t_philo	*next;

	current = *philos;
	while (n_of_p > 0)
	{
		next = current->next;
		pthread_mutex_destroy(&current->forke);
		free(current);
		current = next;
		n_of_p--;
	}
}

void	init_args(t_parameters **args)
{
	t_parameters	*arg;

	arg = *args;
	arg->n_of_p = 0;
	arg->t_to_d = 0;
	arg->t_to_e = 0;
	arg->t_to_s = 0;
	arg->must_e = 0;
	arg->time_s = 0;
	arg->end_sim = false;
	pthread_mutex_init(&arg->sim_mutex, NULL);
	pthread_mutex_init(&arg->print_mutex, NULL);
}

t_philo	*new_philo(int id, t_parameters **args)
{
	t_philo	*new_philo;

	new_philo = malloc(sizeof(t_philo));
	if (!new_philo)
		return (NULL);
	new_philo->id = id;
	new_philo->t_eaten = 0;
	new_philo->last_eat = 0;
	new_philo->full = false;
	pthread_mutex_init(&new_philo->forke, NULL);
	new_philo->args = *args;
	new_philo->next = NULL;
	new_philo->th = NULL;
	return (new_philo);
}

void	init_philos(t_philo	**philos, int n_of_p, t_parameters **args)
{
	t_philo	*current;

	current = new_philo(n_of_p, args);
	if (!current)
		return ;
	n_of_p--;
	*philos = current;
	while (n_of_p > 0)
	{
		current->next = new_philo(n_of_p, args);
		current = current->next;
		n_of_p--;
	}
	current->next = *philos;
}

int	main(int argc, char const *argv[])
{
	t_parameters	*args;
	t_philo			*philos;

	if ((argc != 5 && argc != 6) || ft_is_alpha(argv))
		return (printf("arguments error\n"), 1);
	args = malloc(sizeof(t_parameters));
	if (!args)
		return (printf("malloc error\n"), 1);
	philos = NULL;
	init_args(&args);
	parse(argc, argv, &args);
	init_philos(&philos, args->n_of_p, &args);
	if (!philos)
		return (printf("malloc error\n"), 1);
	sim(&philos);
	pthread_mutex_destroy(&args->print_mutex);
	pthread_mutex_destroy(&args->sim_mutex);
	free_philos(&philos, args->n_of_p);
	free(args);
	return (0);
}
