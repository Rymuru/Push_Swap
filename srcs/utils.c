/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:04:07 by bcoenon           #+#    #+#             */
/*   Updated: 2022/01/31 16:08:29 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	error_manager(t_stack st)
{
	st.len = 0;
	free(st.address);
	write(1, "Error", 6);
	return (st);
}

t_stack	stack_init(t_stack st, int nb, char n)
{
	st.name = n;
	st.len = nb - 1;
	st.address = malloc(st.len * sizeof(int));
	if (!st.address)
	{
		st.len = 0;
	}
	return (st);
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
