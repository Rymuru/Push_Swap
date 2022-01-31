/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:02:30 by bcoenon           #+#    #+#             */
/*   Updated: 2022/01/31 16:21:22 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	solver(t_stack a)
{
	t_stack	b;

	if (is_solved(a) == 0)
		return (a);
	b = stack_init(b, a.len, 'b');
	if (b.len == 0)
		error_manager(a);
	return (a);
}

int	is_solved(t_stack st)
{
	while (st.len > 0)
	{
		if (st.address[st.len] < st.address[st.len - 1])
			return (1);
		st.len--;
	}
	return (0);
}
