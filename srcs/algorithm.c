/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:02:30 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/14 16:31:25 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	/*if (is_solved(a) == 0)
		return (0);*/
	stack_init(b, a->len, 'b');
	if (b->len == 0)
		error_manager(a);
	b->len = 0;
	radix(a, b);
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
