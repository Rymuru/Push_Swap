/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 23:41:57 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/17 01:09:40 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_init(t_stack *a)
{
	t_stack	*b;

	if (is_solved(a) == 0)
		return (0);
	b = malloc(sizeof(t_stack));
	if (!b)
		error_manager(a);
	a->name = 'e';
	stack_init(b, a->len, 'i');
	if (a->len == 5)
	{
		pa_pb(a, b);
		pa_pb(a, b);
	}
	sort_three(a, 0, 0);
	//free_stack(b);
	return (0);
}

void	sort_three(t_stack *a, int min, int max)
{
	min = find_min(min, a);
	max = find_max(max, a);

	if (max == 0)
	{
		if (min == 2)
		{
			sa_sb(a);
			rra_rrb(a);
		}
		else
			ra_rb(a);
	}
	else if (min != 0 && max != 0)
	{
		if (min == 1)
			sa_sb(a);
		else
			rra_rrb(a);
	}
	else
	{
		sa_sb(a);
		ra_rb(a);
	}
}

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
