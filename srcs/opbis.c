/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opbis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:39:19 by bcoenon           #+#    #+#             */
/*   Updated: 2022/03/23 18:52:09 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa_pb(t_stack *st, t_stack *st2)
{
	ft_plusun(st2);
	st->address[0] = st2->address[0];
	ft_moinsun(st);
	write(1, 'p', 1);
	write(1, st->name, 1);
}

void rra_rrb(t_stack *st)
{
	int temp;
	
	temp = st->address[st->len - 1];
	ft_plusun(st);
	st->address[0] = temp;
	if (st->name == 'a')
		write(1, "rra\n", 4);
	else if (st->name == 'b')
		write(1, "rrb\n", 4);
}

void rrr(t_stack *st, t_stack *st2)
{
	int temp;
	
	temp = st->address[st->len - 1];
	ft_plusun(st);
	st->address[0] = temp;
	temp = st2->address[st2->len - 1];
	ft_plusun(st2);
	st2->address[0] = temp;
	write(1, "rrr\n",)
}