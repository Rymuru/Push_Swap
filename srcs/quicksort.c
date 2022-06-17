/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 23:41:57 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/17 02:57:17 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_init(t_stack *a)
{
	t_stack	*b;

	if (is_solved(a) == 0)
		return (0);
	if (a->len == 2)
	{
		sa_sb(a);
		return (0);
	}
	b = malloc(sizeof(t_stack));
	if (!b)
		error_manager(a);
	a->name = 'e';
	stack_init(b, a->len, 'i');
	b->len = 0;
	dispacher(a, b);
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

void	dispacher(t_stack *a, t_stack *b)
{
	if (a->len == 5)
	{
		pa_pb(a, b);
		pa_pb(a, b);
	}
	if (a->len == 4)
		pa_pb(a, b);
	if (is_solved(a) == 1)
		sort_three(a, 0, 0);
	while (b->len)
	{
		quicksolve(a, b, 0);
	}
}

void	quicksolve(t_stack *a, t_stack *b, int i)
{
	pa_pb(b, a);
	i = where_should_i_go(a);
	if (i == 2)
		sa_sb(a);
	else if (i == 3)
	{
		sa_sb(a);
		ra_rb(a);
		sa_sb(a);
		rra_rrb(a);
	}
	else if (i == 4)
	{
		sa_sb(a);
		ra_rb(a);
		sa_sb(a);
		ra_rb(a);
		sa_sb(a);
		rra_rrb(a);
		rra_rrb(a);
	}
	else if (i == 5)
		ra_rb(a);
}
