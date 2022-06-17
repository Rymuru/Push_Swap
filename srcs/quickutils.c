/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:40:47 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/17 17:26:54 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int min, t_stack *a)
{
	if (a->address[0] < a->address[1])
	{
		if (a->address[0] < a->address[2])
			min = 0;
		else
			min = 2;
	}
	else if (a->address[1] < a->address[2])
		min = 1;
	else
		min = 2;
	return (min);
}

int	find_max(int max, t_stack *a)
{
	if (a->address[0] > a->address[1])
	{
		if (a->address[0] > a->address[2])
			max = 0;
		else
			max = 2;
	}
	else if (a->address[1] > a->address[2])
		max = 1;
	else
		max = 2;
	return (max);
}

void	up_low(t_stack *a, t_stack *b)
{
	int	i;
	int	index_min;

	i = 0;
	index_min = 0;
	while (i < a->len)
	{
		if (a->address[i] < a->address[index_min])
			index_min = i;
		i++;
	}
	sattelize(a, b, index_min);
}

void	sattelize(t_stack *a, t_stack *b, int index_min)
{
	if (index_min == 0)
		pa_pb(a, b);
	else if (index_min == 1)
	{
		sa_sb(a);
		pa_pb(a, b);
	}
	else if (index_min == 2)
	{
		ra_rb(a);
		ra_rb(a);
		pa_pb(a, b);
	}
	else if ((index_min == 3 && a->len == 4) || index_min == 4)
	{
		rra_rrb(a);
		pa_pb(a, b);
	}
	else if (index_min == 3 && a->len == 5)
	{
		rra_rrb(a);
		rra_rrb(a);
		pa_pb(a, b);
	}
}
