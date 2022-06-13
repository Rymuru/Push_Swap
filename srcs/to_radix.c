/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:42:45 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/13 17:20:13 by bcoenon          ###   ########.fr       */
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
	size_t	x;
	size_t	tmp_len;

	i = 0;
	tmp_len = a->len;
	while (a->address[i])
	{
		/*if (is_solved(a) == 0 && b->len == 0)
			break ;*/
		while (i < tmp_len)
		{
			x = a->address[0] % 2;
			a->address[0] = a->address[0] / 2;
			if (x == 0)
				pa_pb(a, b);
			else
				ra_rb(a);
			++i;
		}
		while (b->len)
			pa_pb(b, a);
		i = 0;
	}
}
