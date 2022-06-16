/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:42:45 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/16 16:26:49 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stack *easy, t_stack *bis, t_stack *a, t_stack *b)
{
	long int			i;
	long int			tmp_len;

	i = 0;
	tmp_len = easy->len;
	while (is_solved(a) == 1)
	{
		while (i < tmp_len)
		{
			railway(easy, bis, a, b);
			i++;
		}
		while (bis->len)
		{
			pa_pb(bis, easy);
			pa_pb(b, a);
		}
		i = 0;
	}
}

void	railway(t_stack *easy, t_stack *bis, t_stack *a, t_stack *b)
{
	long int	x;

	x = easy->address[0] % 2;
	easy->address[0] = easy->address[0] / 2;
	if (x == 0)
	{
		pa_pb(easy, bis);
		pa_pb(a, b);
	}
	else
	{
		ra_rb(easy);
		ra_rb(a);
	}
}

int	is_solved(t_stack *st)
{
	long int	i;

	i = 0;
	while (i < st->len - 1)
	{
		if (st->address[i] > st->address[i + 1])
			return (1);
		++i;
	}
	return (0);
}
