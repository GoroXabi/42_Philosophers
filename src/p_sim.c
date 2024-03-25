/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:26:23 by xortega           #+#    #+#             */
/*   Updated: 2024/03/21 11:27:14 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watcher(void *philo)
{
	t_philo			*current;

	current = (t_philo *)philo;
	while (!current->args->end_sim)
	{
		dying(current);
		check_full(current, current->args->n_of_p);
		current = current->next;
	}
	return (NULL);
}

void	check_full(t_philo *philo, int n_of_p)
{
	while (n_of_p > 0)
	{
		if (!philo->full)
			return ;
		philo = philo->next;
		n_of_p--;
	}
	philo->args->end_sim = true;
}

void	*rutine(void *philo)
{
	t_philo			*current;

	current = (t_philo *)philo;
	if (current->id % 2)
		usleep(current->args->t_to_e);
	while (!current->args->end_sim)
	{
		if (!current->args->end_sim)
			eating(current);
		if (!current->args->end_sim)
		{
			print_action(current, "is sleeping");
			ft_usleep(current->args->t_to_s);
		}
		if (!current->args->end_sim)
			print_action(current, "is thinking");
	}
	return (NULL);
}

void	sim(t_philo **philos)
{
	t_philo			*current;
	pthread_t		checker;
	int				n_of_philos;

	current = *philos;
	n_of_philos = current->args->n_of_p;
	current->args->time_s = ft_time();
	while (n_of_philos > 0)
	{
		pthread_create(&current->th, NULL, rutine, current);
		n_of_philos--;
		current = current->next;
	}
	current = *philos;
	pthread_create(&checker, NULL, watcher, current);
	n_of_philos = current->args->n_of_p;
	while (n_of_philos > 0)
	{
		pthread_join(current->th, NULL);
		n_of_philos--;
		current = current->next;
	}
	pthread_detach(checker);
}
