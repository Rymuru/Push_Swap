/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:40:47 by bcoenon           #+#    #+#             */
/*   Updated: 2022/06/17 03:53:52 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int min, t_stack *a)
{
	if (a->address[0] < a->address[1])
	{
		if (a->address[0] < a->address[2])
			min = 0;
		else
			min = 2;
	}
	else if (a->address[1] < a->address[2])
		min = 1;
	else
		min = 2;
	return (min);
}

int	find_max(int max, t_stack *a)
{
	if (a->address[0] > a->address[1])
	{
		if (a->address[0] > a->address[2])
			max = 0;
		else
			max = 2;
	}
	else if (a->address[1] > a->address[2])
		max = 1;
	else
		max = 2;
	return (max);
}

int	where_should_i_go(t_stack *a)
{
	int	i;

	i = 0;
	while (a->address[0] >= a->address[i] && i < a->len)
		++i;
	return (i);
}
