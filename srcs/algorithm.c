/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:02:30 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/16 17:57:14 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_stack *a)
{
	t_stack	*b;
	t_stack	*easy;
	t_stack	*bis;
	// int		i = 0;

	b = malloc(sizeof(t_stack));
	
	bis = malloc(sizeof(t_stack));

	easy = malloc(sizeof(t_stack));
	
	if (!b || !easy || !bis)
		error_manager(a);
	stack_init(b, a->len, 'b');
	stack_init(bis, a->len, 'i');
	stack_init(easy, a->len, 'e');
	simplifier(a, easy);
	
	// while (i < easy->len)
	// 	printf("%ld\n", easy->address[i++]);
	// sleep(3);
	
	b->len = 0;
	bis->len = 0;
	radix(easy, bis, a, b);
	free_stack(b);
	free_stack(easy);
	free_stack(bis);
	return (0);
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
		if (a->address[i] <= min && a->address[i] > at_least
			/*&& a->address[i] > INT_MIN && a->address[i] < INT_MAX*/)
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
		if (/*a->address[index_min] != INT_MAX &&*/ a->address[index_min] != INT_MIN)
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
	int	couille = 0;

	i = 0;
	while (i < a->len)
	{
		if (a->address[i] == INT_MIN)
		{
			easy->address[i] = 0;
			couille++;
		}
		i++;
	}
	return (couille);
}
