/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opbis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:39:19 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/17 14:49:14 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb(t_stack *st, t_stack *st2)
{
	ft_plusun(st2);
	st2->address[0] = st->address[0];
	ft_moinsun(st);
	if (st->name == 'e')
		write(1, "pb\n", 3);
	else if (st->name == 'i')
		write(1, "pa\n", 3);
}

void	rra_rrb(t_stack *st)
{
	long int	temp;

	temp = st->address[st->len - 1];
	ft_plusun(st);
	st->len--;
	st->address[0] = temp;
	if (st->name == 'e')
		write(1, "rra\n", 4);
	else if (st->name == 'i')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *st, t_stack *st2)
{
	int	temp;

	temp = st->address[st->len - 1];
	ft_plusun(st);
	st->len--;
	st->address[0] = temp;
	temp = st2->address[st2->len - 1];
	ft_plusun(st2);
	st->len--;
	st2->address[0] = temp;
	write(1, "rrr\n", 4);
}
