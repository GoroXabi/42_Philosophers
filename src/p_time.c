/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_time.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:45:25 by xortega           #+#    #+#             */
/*   Updated: 2024/03/20 17:14:50 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(unsigned int ms)
{
	long	start_time;

	start_time = ft_time();
	while (ft_time() - start_time < ms)
		usleep(10);
}
