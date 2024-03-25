/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xortega <xortega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:38:05 by xortega           #+#    #+#             */
/*   Updated: 2024/03/14 12:22:40 by xortega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_alpha(const char **str)
{
	int	i;
	int	k;

	k = 1;
	while (str[k])
	{
		i = 0;
		while (str[k][i])
		{
			if (str[k][i] < '0' || str[k][i] > '9')
				if (str[k][i] != ' ')
					return (1);
			i++;
		}
		k++;
	}
	return (0);
}

static int	ft_minus(const char *s, int x)
{
	if (s[x] == '-' && (s[x + 1] >= '0' && s[x + 1] <= '9'))
		return (-1);
	if (s[x] == '+' && (s[x + 1] >= '0' && s[x + 1] <= '9'))
		return (1);
	if ((s[x] < '0' || s[x] > '9'))
		return (0);
	if (s[0] == '0' && s[1] == ' ')
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long int	j;
	long int	c;
	long int	x;

	x = 0;
	j = -1;
	c = 0;
	while ((str[++j] <= '\0' && str[j] >= '\10') || str[j] == ' ' || \
	str[j] == '\t' || str[j] == '\n' || str[j] == '\v' || \
	str[j] == '\f' || str[j] == '\r')
		x++;
	while (str[j])
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			if (str[j + 1] >= '0' && str[j + 1] <= '9')
				c = (c * 10) + ((str[j] - 48) * 10);
			else
				c += (str[j] - 48);
		}
		if ((str[j + 1] > '9' || str[j + 1] < '0') && c != 0)
			break ;
		j++;
	}
	return (c * ft_minus(str, x));
}
