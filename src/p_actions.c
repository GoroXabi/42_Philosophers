/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:28 by xortega           #+#    #+#             */
/*   Updated: 2024/03/21 11:27:34 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action)
{
	if (!philo->args->end_sim)
	{
		pthread_mutex_lock(&philo->args->print_mutex);
		if (!philo->args->end_sim)
			printf("%ld %d %s\n", (ft_time() - philo->args->time_s),
				philo->id, action);
		pthread_mutex_unlock(&philo->args->print_mutex);
	}
}

void	dying(t_philo *philo)
{
	t_philo			*current;
	long			time;

	current = philo;
	if (current->last_eat == 0)
		time = 0;
	else
		time = ft_time();
	if ((time - current->last_eat) >= current->args->t_to_d)
	{
		print_action(philo, "died");
		current->args->end_sim = true;
		pthread_mutex_unlock(&current->forke);
		pthread_mutex_unlock(&current->next->forke);
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->forke);
	print_action(philo, "has taken a fork");
	if (philo->args->n_of_p == 1)
	{
		philo->args->end_sim = true;
		printf("%d %d is dead\n", (philo->args->t_to_d), philo->id);
		return ;
	}
	pthread_mutex_lock(&philo->next->forke);
	print_action(philo, "has taken a fork");
	philo->last_eat = ft_time();
	print_action(philo, "is eating");
	philo->t_eaten++;
	if (philo->t_eaten == philo->args->must_e && philo->args->must_e > 0)
		philo->full = 1;
	ft_usleep(philo->args->t_to_e);
	pthread_mutex_unlock(&philo->forke);
	pthread_mutex_unlock(&philo->next->forke);
}
