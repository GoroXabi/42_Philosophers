/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:09:52 by xortega           #+#    #+#             */
/*   Updated: 2024/03/13 12:22:19 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse(int argc, char const *argv[], t_parameters **args)
{
	t_parameters	*arg;

	arg = *args;
	arg->n_of_p = ft_atoi(argv[1]);
	if (arg->n_of_p <= 0)
		return (printf("not a valid argument\n"), exit(1));
	arg->t_to_d = ft_atoi(argv[2]);
	if (arg->t_to_d <= 0)
		return (printf("not a valid argument\n"), exit(1));
	arg->t_to_e = ft_atoi(argv[3]);
	if (arg->t_to_e <= 0)
		return (printf("not a valid argument\n"), exit(1));
	arg->t_to_s = ft_atoi(argv[4]);
	if (arg->t_to_s <= 0)
		return (printf("not a valid argument\n"), exit(1));
	if (argc == 6)
	{
		arg->must_e = ft_atoi(argv[5]);
		if (arg->must_e <= 0)
			return (printf("not a valid argument\n"), exit(1));
	}
}
