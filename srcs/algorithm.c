/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:02:30 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/16 22:55:00 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_stack *a)
{
	t_stack	*b;
	t_stack	*easy;
	t_stack	*bis;

	b = malloc(sizeof(t_stack));
	if (!b)
		error_manager(a);
	bis = malloc(sizeof(t_stack));
	if (!bis)
	{
		free(b);
		error_manager(a);
	}
	easy = malloc(sizeof(t_stack));
	if (!easy)
	{
		free(b);
		free(bis);
		error_manager(a);
	}
	stack_maker(a, b, easy, bis);
	free_stack(b);
	free_stack(easy);
	free_stack(bis);
	return (0);
}

void	stack_maker(t_stack *a, t_stack *b, t_stack *easy, t_stack *bis)
{
	stack_init(b, a->len, 'b');
	stack_init(bis, a->len, 'i');
	stack_init(easy, a->len, 'e');
	simplifier(a, easy);
	b->len = 0;
	bis->len = 0;
	radix(easy, bis, a, b);
}

int	look_for_min(int at_least, t_stack *a)
{
	int	min;
	int	index_min;
	int	i;

	i = 0;
	index_min = 0;
	min = INT_MAX;
	while (i < a->len)
	{
		if (a->address[i] <= min && a->address[i] > at_least)
		{
			min = a->address[i];
			index_min = i;
		}
		++i;
	}
	return (index_min);
}

void	simplifier(t_stack *a, t_stack *easy)
{
	int	i;
	int	min;
	int	index_min;

	i = edge_case(a, easy);
	min = INT_MIN;
	while (i < a->len)
	{
		index_min = look_for_min(min, a);
		if (a->address[index_min] == INT_MAX)
			easy->address[index_min] = a->len - 1;
		if (a->address[index_min] != INT_MIN)
		{
			easy->address[index_min] = i;
			min = a->address[index_min];
		}
		++i;
	}
}

int	edge_case(t_stack *a, t_stack *easy)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < a->len)
	{
		if (a->address[i] == INT_MIN)
		{
			easy->address[i] = 0;
			c++;
		}
		i++;
	}
	return (c);
}
