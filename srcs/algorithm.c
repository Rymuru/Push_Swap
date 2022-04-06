/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:02:30 by bcoenon           #+#    #+#             */
/*   Updated: 2022/04/06 14:21:39 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solver(t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (is_solved(a) == 0)
		return (0);
	stack_init(b, a->len, 'b');
	if (b->len == 0)
		error_manager(a);
	return (0);
}

int	is_solved(t_stack *st)
{
	while (st->len > 0)
	{
		if (st->address[st->len] < st->address[st->len - 1])
			return (1);
		st->len--;
	}
	return (0);
}
