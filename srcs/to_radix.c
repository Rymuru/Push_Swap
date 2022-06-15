/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:42:45 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/15 21:48:22 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stack *a, t_stack *b)
{
	long int	i;
	long int	tmp_len;

	i = 0;
	tmp_len = a->len;
	while (a->address[i])
	{
		while (i < tmp_len)
		{
			railway(a, b);
			i++;
		}
		while (b->len)
			pa_pb(b, a);
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
