/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:02:30 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/14 19:22:43 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_stack *a)
{
	t_stack	*b;
	t_stack	*easy;

	b = malloc(sizeof(t_stack));
	easy = malloc(sizeof(t_stack));
	stack_init(b, a->len, 'b');
	stack_init(easy, a->len, 'a');
	if (b->len == 0 || easy->len == 0)
		error_manager(a);
	simplifier(a, easy);
	b->len = 0;
	radix(easy, b);
	return (0);
}

int	is_solved(t_stack *st)
{
	size_t	i;

	i = 0;
	while (i < st->len)
	{
		if (st->address[i] > st->address[i + 1])
			return (1);
		++i;
	}
	return (0);
}

void	simplifier(t_stack *a, t_stack *easy)
{
	size_t		c;
	size_t		i;
	long int	x;
	long int	ret;

	c = 0;
	i = 1;
	x = a->address[0];
	ret = -2147483648;

	while (c < a->len)
	{
		while (i < a->len)
		{
			if (a->address[i] < x && a->address[i] > ret)
				x = a->address[i];
			easy->address[i] = c;
			++i;
		}
		ret = x;
		i = 0;
		++c;
	}
}