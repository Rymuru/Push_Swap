/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:42:45 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/14 16:39:37 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bitconvert(t_stack *st)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (z < st->len)
	{
		while (i < sizeof(int) * 8)
		{
			st->address[z] = (st->address[z] >> i) & 1;
			++i;
		}
		i = 0;
	++z;
	}
}

void	radix(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	tmp_len;

	i = 0;
	tmp_len = a->len;
	while (a->address[i])
	{
		while (i < tmp_len)
		{
			if (a->address[0] >= 0)
				railway(a, b);
			else
				invert(a, b);
			if (is_solved(a) == 0 && b->len == 0)
			{
				break ;
			}
			++i;
		}
		while (b->len)
			pa_pb(b, a);
		if (is_solved(a) == 0 && b->len == 0)
			break ;
		i = 0;
	}
}

void	railway(t_stack *a, t_stack *b)
{
	long int	x;

	x = a->address[0] % 2;
	a->address[0] = a->address[0] / 2;
	if (x == 0)
		pa_pb(a, b);
	else
		ra_rb(a);
}


void	invert(t_stack *a, t_stack *b)
{
	long int	x;

	x = a->address[0] % 2;
	a->address[0] = a->address[0] / 2;
	if (x == 1)
		pa_pb(a, b);
	else
		ra_rb(a);
}