/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:04:07 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/18 18:31:17 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *st)
{
	free(st->address);
	free(st);
}

int	error_manager(t_stack *st)
{
	st->len = 0;
	free(st->address);
	write(2, "Error\n", 6);
	return (1);
}

int	stack_init(t_stack *st, int nb, char n)
{
	st->name = n;
	st->len = nb;
	st->address = malloc((st->len +1) * sizeof(long int));
	if (!st->address)
	{
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
		++i;
	return (i);
}

long int	ft_atoi(char *str)
{
	long int	i;
	long int	num;
	long int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}
