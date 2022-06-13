/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:29:52 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/13 17:01:52 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack *st)
{
	int	temp;

	temp = st->address[0];
	st->address[0] = st->address[1];
	st->address[1] = st->address[temp];
	if (st->name == 'a')
		write(1, "sa\n", 3);
	else if (st->name == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_stack *st, t_stack *st2)
{
	int	temp;

	temp = st->address[0];
	st->address[0] = st->address[1];
	st->address[1] = st->address[temp];
	temp = st2->address[0];
	st2->address[0] = st2->address[1];
	st2->address[1] = st2->address[temp];
	write(1, "ss\n", 3);
}

void	ra_rb(t_stack *st)
{
	size_t	i;
	int		temp;

	i = 0;
	temp = st->address[0];
	while (i + 1 < st->len)
	{
		st->address[i] = st->address[i + 1];
		i++;
	}
	st->address[i] = temp;
	if (st->name == 'a')
		write(1, "ra\n", 3);
	else if (st->name == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_stack *st, t_stack *st2)
{
	size_t	i;
	int		temp;

	i = 0;
	temp = st->address[i];
	while (i < st->len)
	{
		st->address[i] = st->address[i + 1];
		i++;
	}
	st->address[0] = temp;
	i = 0;
	temp = st2->address[i];
	while (i < st2->len)
	{
		st2->address[i] = st2->address[i + 1];
		i++;
	}
	st2->address[0] = temp;
	write(1, "rr", 3);
}
